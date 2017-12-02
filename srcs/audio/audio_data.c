/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:19:08 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/02 21:06:23 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	refresh_audio(t_sound *sound)
{
	FMOD_RESULT	err;

	if ((err = FMOD_System_Update(sound->system)) != FMOD_OK)
		error_exit("Failed to update FMOD System");
	if ((err = FMOD_DSP_GetParameterData(sound->fft,
			FMOD_DSP_FFT_SPECTRUMDATA, (void*)&sound->data->spec,
			0, 0, 0)))
		error_exit("");
}

static void	analyze_fft_output(t_audiodata *data)
{
	
	(data->p_spec)[0] = (data->spec->spectrum)[0][1];
	(data->p_spec)[1] = (data->spec->spectrum)[0][3];
	(data->p_spec)[2] = (data->spec->spectrum)[0][10];

	if (data->p_spec[0] > 0.2)
	printf("0:%f  1:%f  2:%f  \n", data->p_spec[0], data->p_spec[1], data->p_spec[2]);
}

void		get_audio_data(t_sound *sound)
{
	refresh_audio(sound);
	analyze_fft_output(sound->data);
}
