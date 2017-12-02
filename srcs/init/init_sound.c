/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sound.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:30:26 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/02 21:04:47 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	system_init(t_sound *sound)
{
	FMOD_RESULT	err;

	if ((err = FMOD_System_Create(&(sound->system))) != FMOD_OK)
		error_exit("FMOD Failed to create system");
	if ((err = FMOD_System_Init(sound->system, 512,
					FMOD_INIT_NORMAL, 0)) != FMOD_OK)
		error_exit("FMOD Failed to init system");
}

static void	channel_init(t_sound *sound)
{
	FMOD_RESULT	err;

	if ((err = FMOD_System_CreateStream(sound->system, "res/tired", 
					FMOD_DEFAULT, 0, &(sound->song))) != FMOD_OK)
		error_exit("FMOD Failed to open audio file");
	if ((err = FMOD_System_PlaySound(sound->system, sound->song,
					0, 0, &(sound->channel))) != FMOD_OK)
		error_exit("FMOD Failed to play audio");
}

static void	dsp_init(t_sound *sound)
{
	FMOD_RESULT	err;

	if ((err = FMOD_System_CreateDSPByType(sound->system,
					FMOD_DSP_TYPE_FFT, &sound->fft)) != FMOD_OK)
		error_exit("FMOD Failed to create system");
	if ((err = FMOD_DSP_SetParameterInt(sound->fft,
					FMOD_DSP_FFT_WINDOWSIZE, 256)) != FMOD_OK)
		error_exit("FMOD Failed to create system");
	if ((err = FMOD_Channel_AddDSP(sound->channel, 0,
					sound->fft)) != FMOD_OK)
		error_exit("FMOD Failed to create system");
}

void	init_sound(t_sound *sound)
{
	if (!(sound->data = ft_memalloc(sizeof(t_audiodata))))
		error_exit("");
	system_init(sound);
	channel_init(sound);
	dsp_init(sound);
}
