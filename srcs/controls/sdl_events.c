/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:18:33 by lbelda            #+#    #+#             */
/*   Updated: 2018/03/15 18:13:43 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	handle_button(t_env *e, SDL_GameControllerButton button, int flag)
{
	if (button == SDL_CONTROLLER_BUTTON_LEFTSHOULDER)
		ps3_camrotz(e, flag);
	else if (button == SDL_CONTROLLER_BUTTON_RIGHTSHOULDER)
		ps3_camrotz(e, -flag);
	else if (button == SDL_CONTROLLER_BUTTON_A)
		k_chcolor_stock(e, flag);
	else if (button == SDL_CONTROLLER_BUTTON_B)
		k_chspace(e, flag);
	else if (button == SDL_CONTROLLER_BUTTON_Y)
		k_chbuff_mode(e, flag);
}

static void	handle_axis(t_env *e, SDL_ControllerAxisEvent caxis)
{
	caxis.value = (iabs(caxis.value) > 3500 ? caxis.value : 0);
	if (caxis.axis == SDL_CONTROLLER_AXIS_LEFTX)
		ps3_camroty(e, caxis.value);
	else if (caxis.axis == SDL_CONTROLLER_AXIS_LEFTY)
		ps3_camrotx(e, caxis.value);
	else if (caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERLEFT)
		ps3_camtrsz(e, -caxis.value);
	else if (caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT)
		ps3_camtrsz(e, caxis.value);
}

void		handle_sdl_events(t_env *e)
{
	SDL_Event	event;

	if (e->controls->active[0].keycode != K_LEFT)
		return ;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_CONTROLLERAXISMOTION)
			handle_axis(e, event.caxis);
		else if (event.type == SDL_CONTROLLERBUTTONDOWN)
			handle_button(e, event.cbutton.button, 1);
		else if (event.type == SDL_CONTROLLERBUTTONUP)
			handle_button(e, event.cbutton.button, 0);
	}
}
