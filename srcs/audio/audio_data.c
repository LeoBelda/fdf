/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:19:08 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/03 16:04:36 by lbelda           ###   ########.fr       */
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

static float	get_total_spec(FMOD_DSP_PARAMETER_FFT *spec)
{
	int		chan;
	int		bin;
	float	total;

	chan = 0;
	total = 0;
	while (chan < spec->numchannels)
	{
		bin = 0;
		while (bin < spec->length / 2)
		{
			total += spec->spectrum[chan][bin];
			bin++;
		}
		chan++;
	}
	total /= (chan * bin / 2);
	return (total);
}

static void		analyze_fft_output(t_audiodata *data)
{
	
	data->p_spec->low_band = (data->spec->spectrum[0][1]
							+ data->spec->spectrum[1][1]) / 2.0;
	if (data->p_spec->low_band < 0.1)
		data->p_spec->low_band = 0.0;
	data->p_spec->mid_band = (data->spec->spectrum[0][4]
							+ data->spec->spectrum[1][4]) / 2.0;
	data->p_spec->high_band = (data->spec->spectrum[0][15]
							+ data->spec->spectrum[1][15]) / 2.0;
	data->p_spec->total = get_total_spec(data->spec);
	if (data->p_spec->low_band > 0.2)
	printf("0:%f  1:%f  2:%f  \n", data->p_spec->low_band, data->p_spec->mid_band, data->p_spec->high_band);
}

void		get_audio_data(t_sound *sound)
{
	refresh_audio(sound);
	analyze_fft_output(sound->data);
}
