/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sound.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:30:26 by lbelda            #+#    #+#             */
/*   Updated: 2017/12/04 21:14:31 by lbelda           ###   ########.fr       */
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

static int	channel_init(t_sound *sound, char *file)
{
	FMOD_RESULT	err;

	if ((err = FMOD_System_CreateStream(sound->system, file, 
					FMOD_DEFAULT, 0, &(sound->song))) != FMOD_OK)
		return (0);
	if ((err = FMOD_System_PlaySound(sound->system, sound->song,
					0, 0, &(sound->channel))) != FMOD_OK)
		error_exit("FMOD Failed to play audio");
	return (1);
}

static void	dsp_init(t_sound *sound)
{
	FMOD_RESULT	err;
	int			i;

	i = 0;
	if ((err = FMOD_System_CreateDSPByType(sound->system,
					FMOD_DSP_TYPE_FFT, &sound->fft)) != FMOD_OK)
		error_exit("FMOD Failed to create DSP");
	if ((err = FMOD_DSP_SetParameterInt(sound->fft,
					FMOD_DSP_FFT_WINDOWSIZE, FFT_SIZE)) != FMOD_OK)
		error_exit("FMOD Failed to configure DSP");
	if ((err = FMOD_Channel_AddDSP(sound->channel, 0,
					sound->fft)) != FMOD_OK)
		error_exit("FMOD Failed to connect DSP");
	if ((err = FMOD_System_Update(sound->system)) != FMOD_OK)
		error_exit("Failed to update FMOD System");
	if ((err = FMOD_DSP_GetParameterData(sound->fft,
			FMOD_DSP_FFT_SPECTRUMDATA, (void*)&sound->data->spec,
			0, 0, 0)))
		error_exit("");
	if (!(sound->data->oct = ft_memalloc(
					sizeof(float*) * 2)))
		error_exit("");
	while (i < 2)
	{
		if (!(sound->data->oct[i] = ft_memalloc(sizeof(float) * OCT_NB)))
			error_exit("");
		i++;
	}
	ft_putnbr(sound->data->spec->numchannels);
}

void	init_sound(t_sound *sound, char *file)
{
	if (!(sound->data = ft_memalloc(sizeof(t_audiodata))))
		error_exit("");
	if (!(sound->data->p_spec = ft_memalloc(sizeof(t_spec))))
		error_exit("");
	system_init(sound);
	if (channel_init(sound, file))
	{
		sound->mode = S_ON;
		dsp_init(sound);
	}
}
