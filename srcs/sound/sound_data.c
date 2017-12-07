/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:19:08 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/06 21:15:29 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		refresh_audio(t_sound *sound)
{
	FMOD_RESULT	err;

	if ((err = FMOD_System_Update(sound->system)) != FMOD_OK)
		error_exit("Failed to update FMOD System");
	if ((err = FMOD_DSP_GetParameterData(sound->fft,
			FMOD_DSP_FFT_SPECTRUMDATA, (void*)&sound->data->spec,
			0, 0, 0)))
		error_exit("");
}

static float	get_total_spec(float **oct)
{
	int		chan;
	int		noct;
	float	total;

	chan = 0;
	total = 0;
	while (chan < 2)
	{
		noct = 0;
		while (noct < OCT_NB)
		{
			total += oct[chan][noct];
			noct++;
		}
		chan++;
	}
	total /= (chan * noct);
	return (total);
}

static float	get_bins(float *bins, size_t a, size_t b)
{
	size_t	i;
	float	total;

	i = a;
	total = 0;
	while (i < b)
	{
		total += bins[i];
		i++;
	}
	return (total);
}

static void		freq_to_oct(t_audiodata *data)
{
	int	nbchan;

	nbchan = 0;
	while (nbchan < data->spec->numchannels)
	{
		data->oct[nbchan][0] = get_bins(data->spec->spectrum[nbchan], 1, 2);
		data->oct[nbchan][1] = get_bins(data->spec->spectrum[nbchan], 2, 4);
		data->oct[nbchan][2] = get_bins(data->spec->spectrum[nbchan], 4, 8);
		data->oct[nbchan][3] = get_bins(data->spec->spectrum[nbchan], 8, 16);
		data->oct[nbchan][4] = get_bins(data->spec->spectrum[nbchan], 16, 32);
		data->oct[nbchan][5] = get_bins(data->spec->spectrum[nbchan], 32, 64);
		data->oct[nbchan][6] = get_bins(data->spec->spectrum[nbchan], 64, 128);
		data->oct[nbchan][7] = get_bins(data->spec->spectrum[nbchan], 128, 256);
		data->oct[nbchan][8] = get_bins(data->spec->spectrum[nbchan], 256, 512);
		nbchan++;
	}
}

static void		analyze_fft_output(t_audiodata *data)
{
	freq_to_oct(data);
	data->p_spec->low_band = (data->oct[0][0]
							+ data->oct[1][0]) / 2.0;
	if (data->p_spec->low_band < 0.1)
		data->p_spec->low_band = 0.0;
	data->p_spec->total = get_total_spec(data->oct) * 10.0;
	if (data->p_spec->total < 0.1)
		data->p_spec->total = 0.0;
}

void		get_sound_data(t_sound *sound)
{
	if (sound->smode == S_ON)
	{
		refresh_audio(sound);
		analyze_fft_output(sound->data);
	}
}
