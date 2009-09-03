/*
 *  vdpau_gate.c - VDPAU hooks
 *
 *  vdpau-video (C) 2009 Splitted-Desktop Systems
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#include "sysdeps.h"
#include "vdpau_gate.h"
#include "vdpau_video.h"

#define DEBUG 1
#include "debug.h"


// VdpVideoSurfaceCreate
VdpStatus
vdpau_video_surface_create(
    vdpau_driver_data_t *driver_data,
    VdpDevice            device,
    VdpChromaType        chroma_type,
    uint32_t             width,
    uint32_t             height,
    VdpVideoSurface     *surface
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_video_surface_create == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_video_surface_create(device,
                                                            chroma_type,
                                                            width,
                                                            height,
                                                            surface);
}

// VdpVideoSurfaceDestroy
VdpStatus
vdpau_video_surface_destroy(
    vdpau_driver_data_t *driver_data,
    VdpVideoSurface      surface
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_video_surface_destroy == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_video_surface_destroy(surface);
}

// VdpVideoSurfaceGetBitsYCbCr
VdpStatus
vdpau_video_surface_get_bits_ycbcr(
    vdpau_driver_data_t *driver_data,
    VdpVideoSurface      surface,
    VdpYCbCrFormat       format,
    uint8_t            **dest,
    uint32_t            *stride
)
{
    if (driver_data < 0)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_video_surface_get_bits_ycbcr == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_video_surface_get_bits_ycbcr(surface, format,
                                                                    (void * const *)dest,
                                                                    stride);
}

// VdpOutputSurfaceCreate
VdpStatus
vdpau_output_surface_create(
    vdpau_driver_data_t *driver_data,
    VdpDevice            device,
    VdpRGBAFormat        rgba_format,
    uint32_t             width,
    uint32_t             height,
    VdpOutputSurface    *surface
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_output_surface_create == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_output_surface_create(device,
                                                             rgba_format,
                                                             width,
                                                             height,
                                                             surface);
}

// VdpOutputSurfaceDestroy
VdpStatus
vdpau_output_surface_destroy(
    vdpau_driver_data_t *driver_data,
    VdpOutputSurface     surface
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_output_surface_destroy == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_output_surface_destroy(surface);
}

// VdpOutputSurfaceGetBitsNative
VdpStatus
vdpau_output_surface_get_bits_native(
    vdpau_driver_data_t *driver_data,
    VdpOutputSurface     surface,
    const VdpRect       *source_rect,
    uint8_t            **dst,
    uint32_t            *stride
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_output_surface_get_bits_native == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_output_surface_get_bits_native(surface,
                                                                      source_rect,
                                                                      (void * const *)dst,
                                                                      stride);
}

// VdpVideoMixerCreate
VdpStatus
vdpau_video_mixer_create(
    vdpau_driver_data_t          *driver_data,
    VdpDevice                     device,
    uint32_t                      feature_count,
    VdpVideoMixerFeature const   *features,
    uint32_t                      parameter_count,
    VdpVideoMixerParameter const *parameters,
    const void                   *parameter_values,
    VdpVideoMixer                *mixer
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_video_mixer_create == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_video_mixer_create(device,
                                                          feature_count,
                                                          features,
                                                          parameter_count,
                                                          parameters,
                                                          parameter_values,
                                                          mixer);
}

// VdpVideoMixerDestroy
VdpStatus
vdpau_video_mixer_destroy(
    vdpau_driver_data_t *driver_data,
    VdpVideoMixer        mixer
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_video_mixer_destroy == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_video_mixer_destroy(mixer);
}

// VdpVideoMixerRender
VdpStatus
vdpau_video_mixer_render(
    vdpau_driver_data_t          *driver_data,
    VdpVideoMixer                 mixer,
    VdpOutputSurface              background_surface,
    const VdpRect                *background_source_rect,
    VdpVideoMixerPictureStructure current_picture_structure,
    uint32_t                      video_surface_past_count,
    const VdpVideoSurface        *video_surface_past,
    VdpVideoSurface               video_surface_current,
    uint32_t                      video_surface_future_count,
    const VdpVideoSurface        *video_surface_future,
    const VdpRect                *video_source_rect,
    VdpOutputSurface              destination_surface,
    const VdpRect                *destination_rect,
    const VdpRect                *destination_video_rect,
    uint32_t                      layer_count,
    const VdpLayer               *layers
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_video_mixer_render == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_video_mixer_render(mixer,
                                                          background_surface,
                                                          background_source_rect,
                                                          current_picture_structure,
                                                          video_surface_past_count,
                                                          video_surface_past,
                                                          video_surface_current,
                                                          video_surface_future_count,
                                                          video_surface_future,
                                                          video_source_rect,
                                                          destination_surface,
                                                          destination_rect,
                                                          destination_video_rect,
                                                          layer_count,
                                                          layers);
}

// VdpPresentationQueueCreate
VdpStatus
vdpau_presentation_queue_create(
    vdpau_driver_data_t       *driver_data,
    VdpDevice                  device,
    VdpPresentationQueueTarget presentation_queue_target,
    VdpPresentationQueue      *presentation_queue
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_presentation_queue_create == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_presentation_queue_create(device,
                                                                 presentation_queue_target,
                                                                 presentation_queue);
}

// VdpPresentationQueueDestroy
VdpStatus
vdpau_presentation_queue_destroy(
    vdpau_driver_data_t *driver_data,
    VdpPresentationQueue presentation_queue
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_presentation_queue_destroy == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_presentation_queue_destroy(presentation_queue);
}

// VdpPresentationQueueDisplay
VdpStatus
vdpau_presentation_queue_display(
    vdpau_driver_data_t *driver_data,
    VdpPresentationQueue presentation_queue,
    VdpOutputSurface     surface,
    uint32_t             clip_width,
    uint32_t             clip_height,
    VdpTime              earliest_presentation_time
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_presentation_queue_display == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_presentation_queue_display(presentation_queue,
                                                                  surface,
                                                                  clip_width,
                                                                  clip_height,
                                                                  earliest_presentation_time);
}

// VdpPresentationQueueBlockUntilSurfaceIdle
VdpStatus
vdpau_presentation_queue_block_until_surface_idle(
    vdpau_driver_data_t *driver_data,
    VdpPresentationQueue presentation_queue,
    VdpOutputSurface     surface,
    VdpTime             *first_presentation_time
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_presentation_queue_block_until_surface_idle == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_presentation_queue_block_until_surface_idle(presentation_queue,
                                                                                   surface,
                                                                                   first_presentation_time);
}

// VdpPresentationQueueQuerySurfaceStatus
VdpStatus
vdpau_presentation_queue_query_surface_status(
    vdpau_driver_data_t        *driver_data,
    VdpPresentationQueue        presentation_queue,
    VdpOutputSurface            surface,
    VdpPresentationQueueStatus *status,
    VdpTime                    *first_presentation_time
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_presentation_queue_query_surface_status == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_presentation_queue_query_surface_status(presentation_queue,
                                                                               surface,
                                                                               status,
                                                                               first_presentation_time);
}

// VdpPresentationQueueTargetCreateX11
VdpStatus
vdpau_presentation_queue_target_create_x11(
    vdpau_driver_data_t        *driver_data,
    VdpDevice                   device,
    Drawable                    drawable,
    VdpPresentationQueueTarget *target
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_presentation_queue_target_create_x11 == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_presentation_queue_target_create_x11(device,
                                                                            drawable,
                                                                            target);
}

// VdpPresentationQueueTargetDestroy
VdpStatus
vdpau_presentation_queue_target_destroy(
    vdpau_driver_data_t       *driver_data,
    VdpPresentationQueueTarget presentation_queue_target
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_presentation_queue_target_destroy == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_presentation_queue_target_destroy(presentation_queue_target);
}

// VdpDecoderCreate
VdpStatus
vdpau_decoder_create(
    vdpau_driver_data_t *driver_data,
    VdpDevice            device,
    VdpDecoderProfile    profile,
    uint32_t             width,
    uint32_t             height,
    uint32_t             max_references,
    VdpDecoder          *decoder
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_decoder_create == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_decoder_create(device,
                                                      profile,
                                                      width,
                                                      height,
                                                      max_references,
                                                      decoder);
}

// VdpDecoderDestroy
VdpStatus
vdpau_decoder_destroy(
    vdpau_driver_data_t *driver_data,
    VdpDecoder           decoder
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_decoder_destroy == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_decoder_destroy(decoder);
}

// VdpDecoderRender
VdpStatus
vdpau_decoder_render(
    vdpau_driver_data_t      *driver_data,
    VdpDecoder                decoder,
    VdpVideoSurface           target,
    VdpPictureInfo const     *picture_info,
    uint32_t                  bitstream_buffers_count,
    VdpBitstreamBuffer const *bitstream_buffers
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_decoder_render == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_decoder_render(decoder,
                                                      target,
                                                      picture_info,
                                                      bitstream_buffers_count,
                                                      bitstream_buffers);
}

// VdpDecoderQueryCapabilities
VdpStatus
vdpau_decoder_query_capabilities(
    vdpau_driver_data_t *driver_data,
    VdpDevice            device,
    VdpDecoderProfile    profile,
    VdpBool             *is_supported,
    uint32_t            *max_level,
    uint32_t            *max_references,
    uint32_t            *max_width,
    uint32_t            *max_height
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_decoder_query_capabilities == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_decoder_query_capabilities(device,
                                                                  profile,
                                                                  is_supported,
                                                                  max_level,
                                                                  max_references,
                                                                  max_width,
                                                                  max_height);
}

// VdpVideoSurfaceQueryGetPutBitsYCbCrCapabilities
VdpStatus
vdpau_video_surface_query_ycbcr_caps(
    vdpau_driver_data_t *driver_data,
    VdpDevice            device,
    VdpChromaType        surface_chroma_type,
    VdpYCbCrFormat       bits_ycbcr_format,
    VdpBool             *is_supported
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_video_surface_query_ycbcr_caps == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_video_surface_query_ycbcr_caps(device,
                                                                      surface_chroma_type,
                                                                      bits_ycbcr_format,
                                                                      is_supported);
}

// VdpOutputSurfaceQueryGetPutBitsNativeCapabilities
VdpStatus
vdpau_output_surface_query_rgba_caps(
    vdpau_driver_data_t *driver_data,
    VdpDevice            device,
    VdpRGBAFormat        surface_rgba_format,
    VdpBool             *is_supported
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_output_surface_query_rgba_caps == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_output_surface_query_rgba_caps(device,
                                                                      surface_rgba_format,
                                                                      is_supported);
}

// VdpGetApiVersion
VdpStatus
vdpau_get_api_version(vdpau_driver_data_t *driver_data, uint32_t *api_version)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_get_api_version == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_get_api_version(api_version);
}

// VdpGetInformationString
VdpStatus
vdpau_get_information_string(
    vdpau_driver_data_t *driver_data,
    const char         **info_string
)
{
    if (driver_data == NULL)
        return VDP_STATUS_INVALID_POINTER;
    if (driver_data->vdp_vtable.vdp_get_information_string == NULL)
        return VDP_STATUS_INVALID_POINTER;
    return driver_data->vdp_vtable.vdp_get_information_string(info_string);
}

// VdpGetErrorString
const char *
vdpau_get_error_string(vdpau_driver_data_t *driver_data, VdpStatus vdp_status)
{
    if (driver_data == NULL)
        return NULL;
    if (driver_data->vdp_vtable.vdp_get_error_string == NULL)
        return NULL;
    return driver_data->vdp_vtable.vdp_get_error_string(vdp_status);
}
