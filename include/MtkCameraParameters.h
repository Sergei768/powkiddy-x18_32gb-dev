/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein is
 * confidential and proprietary to MediaTek Inc. and/or its licensors. Without
 * the prior written permission of MediaTek inc. and/or its licensors, any
 * reproduction, modification, use or disclosure of MediaTek Software, and
 * information contained herein, in whole or in part, shall be strictly
 * prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER
 * ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR
 * NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH
 * RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 * INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES
 * TO LOOK ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO.
 * RECEIVER EXPRESSLY ACKNOWLEDGES THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO
 * OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES CONTAINED IN MEDIATEK
 * SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE
 * RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S
 * ENTIRE AND CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE
 * RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE
 * MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE
 * CHARGE PAID BY RECEIVER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek
 * Software") have been modified by MediaTek Inc. All revisions are subject to
 * any receiver's applicable license agreements with MediaTek Inc.
 */

/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _MTK_HARDWARE_MTKCAM_INCLUDE_MTKCAM_UTILS_FWK_MTKCAMERAPARAMETERS_H
#define _MTK_HARDWARE_MTKCAM_INCLUDE_MTKCAM_UTILS_FWK_MTKCAMERAPARAMETERS_H

#include <camera/CameraParameters.h>

namespace android {






class MtkCameraParameters : public CameraParameters
{
public:
    MtkCameraParameters() : CameraParameters() {}
    MtkCameraParameters(const String8 &params) { unflatten(params); }
    ~MtkCameraParameters()  {}

    MtkCameraParameters& operator=(CameraParameters const& params)
    {
        unflatten(params.flatten());
        return  (*this);
    }

    void setPreviewSize(int width, int height);
    void getPreviewSize(int *width, int *height) const;















    static int queryImageFormat(String8 const& s8PixelFormat);
    static int queryImageFormat(char const* szPixelFormat);




    static const char PROPERTY_KEY_CLIENT_APPMODE[];

    static const char APP_MODE_NAME_DEFAULT[];
    static const char APP_MODE_NAME_MTK_ENG[];
    static const char APP_MODE_NAME_MTK_ATV[];
    static const char APP_MODE_NAME_MTK_STEREO[];
    static const char APP_MODE_NAME_MTK_VT[];
    static const char APP_MODE_NAME_MTK_PHOTO[];
    static const char APP_MODE_NAME_MTK_VIDEO[];
    static const char APP_MODE_NAME_MTK_ZSD[];




    static const char SCENE_MODE_NORMAL[];




    static const char KEY_FB_SMOOTH_LEVEL[];
    static const char KEY_FB_SMOOTH_LEVEL_MIN[];
    static const char KEY_FB_SMOOTH_LEVEL_MAX[];
    static const char KEY_FB_SMOOTH_LEVEL_Default[];

    static const char KEY_FB_SKIN_COLOR[];
    static const char KEY_FB_SKIN_COLOR_MIN[];
    static const char KEY_FB_SKIN_COLOR_MAX[];
    static const char KEY_FB_SKIN_COLOR_Default[];

    static const char KEY_FB_SHARP[];
    static const char KEY_FB_SHARP_MIN[];
    static const char KEY_FB_SHARP_MAX[];

    static const char KEY_FB_ENLARGE_EYE[];
    static const char KEY_FB_ENLARGE_EYE_MIN[];
    static const char KEY_FB_ENLARGE_EYE_MAX[];

    static const char KEY_FB_SLIM_FACE[];
    static const char KEY_FB_SLIM_FACE_MIN[];
    static const char KEY_FB_SLIM_FACE_MAX[];

    static const char KEY_FB_EXTREME_BEAUTY[];

    static const char KEY_FB_TOUCH_POS[];

    static const char KEY_FB_FACE_POS[];

    static const char KEY_FACE_BEAUTY[];

    static const char KEY_FB_EXTREME_SUPPORTED[];

    static const char KEY_FEATURE_MAX_FPS[];

    static const char KEY_VIDEO_FACE_BEAUTY_SUPPORTED[];




    static const char KEY_EXPOSURE[];
    static const char KEY_EXPOSURE_METER[];
    static const char KEY_ISO_SPEED[];
    static const char KEY_AE_MODE[];
    static const char KEY_FOCUS_METER[];
    static const char KEY_EDGE[];
    static const char KEY_HUE[];
    static const char KEY_SATURATION[];
    static const char KEY_BRIGHTNESS[];
    static const char KEY_CONTRAST[];
    static const char KEY_ZSD_MODE[];
    static const char KEY_SUPPORTED_ZSD_MODE[];
    static const char KEY_AWB2PASS[];
    static const char KEY_AF_LAMP_MODE [];

    static const char KEY_STEREO_3D_PREVIEW_SIZE[];
    static const char KEY_STEREO_3D_PICTURE_SIZE[];
    static const char KEY_STEREO_3D_TYPE [];
    static const char KEY_STEREO_3D_MODE [];
    static const char KEY_STEREO_3D_IMAGE_FORMAT [];

    static const char KEY_FPS_MODE[];

    static const char KEY_FOCUS_DRAW[];

    static const char KEY_CAPTURE_MODE[];
    static const char KEY_SUPPORTED_CAPTURE_MODES[];
    static const char KEY_CAPTURE_PATH[];
    static const char KEY_BURST_SHOT_NUM[];

    static const char KEY_MATV_PREVIEW_DELAY[];

    static const char KEY_PANORAMA_IDX[];
    static const char KEY_PANORAMA_DIR[];

    static const char KEY_SENSOR_DEV[];
    static const char KEY_SUPPORTED_SENSOR_DEVS[];


    static const char EXPOSURE_METER_SPOT[];
    static const char EXPOSURE_METER_CENTER[];
    static const char EXPOSURE_METER_AVERAGE[];


    static const char ISO_SPEED_AUTO[];
    static const char ISO_SPEED_100[];
    static const char ISO_SPEED_200[];
    static const char ISO_SPEED_400[];
    static const char ISO_SPEED_800[];
    static const char ISO_SPEED_1600[];


    static const char FOCUS_METER_SPOT[];
    static const char FOCUS_METER_MULTI[];

    static const char KEY_CAMERA_MODE[];

    static const int CAMERA_MODE_NORMAL;
    static const int CAMERA_MODE_MTK_PRV;
    static const int CAMERA_MODE_MTK_VDO;
    static const int CAMERA_MODE_MTK_VT;


    static const int FPS_MODE_NORMAL;
    static const int FPS_MODE_FIX;


    static const char CAPTURE_MODE_PANORAMA_SHOT[];
    static const char CAPTURE_MODE_BURST_SHOT[];
    static const char CAPTURE_MODE_NORMAL[];
    static const char CAPTURE_MODE_BEST_SHOT[];
    static const char CAPTURE_MODE_EV_BRACKET_SHOT[];
    static const char CAPTURE_MODE_SMILE_SHOT[];
    static const char CAPTURE_MODE_AUTO_PANORAMA_SHOT[];
    static const char CAPTURE_MODE_MOTION_TRACK_SHOT[];
    static const char CAPTURE_MODE_MAV_SHOT[];
    static const char CAPTURE_MODE_HDR_SHOT[];
    static const char CAPTURE_MODE_ASD_SHOT[];
    static const char CAPTURE_MODE_ZSD_SHOT[];
    static const char CAPTURE_MODE_PANO_3D[];
    static const char CAPTURE_MODE_SINGLE_3D[];
    static const char CAPTURE_MODE_FACE_BEAUTY[];
    static const char CAPTURE_MODE_CONTINUOUS_SHOT[];
    static const char CAPTURE_MODE_MULTI_MOTION[];
    static const char CAPTURE_MODE_GESTURE_SHOT[];


    static const char PANORAMA_DIR_RIGHT[];
    static const char PANORAMA_DIR_LEFT[];
    static const char PANORAMA_DIR_TOP[];
    static const char PANORAMA_DIR_DOWN[];

    static const int ENABLE;
    static const int DISABLE;


    static const char HIGH[];
    static const char MIDDLE[];
    static const char LOW[];


    static const char KEY_PREVIEW_INT_FORMAT[];



    static const char PIXEL_FORMAT_YUV420I[];































    static const char PIXEL_FORMAT_YV12_GPU[];










    static const char PIXEL_FORMAT_YUV422I_UYVY[];

    static const char PIXEL_FORMAT_YUV422I_VYUY[];
    static const char PIXEL_FORMAT_YUV422I_YVYU[];
    static const char PIXEL_FORMAT_BAYER8[];
    static const char PIXEL_FORMAT_BAYER10[];
    static const char PIXEL_FORMAT_BITSTREAM[];
    static const char PIXEL_FORMAT_YUV420SP_NV12[];






    static const char KEY_BRIGHTNESS_VALUE[];


    static const char KEY_ISP_MODE[];

    static const char KEY_AF_X[];
    static const char KEY_AF_Y[];
    static const char KEY_FOCUS_ENG_MAX_STEP[];
    static const char KEY_FOCUS_ENG_MIN_STEP[];
    static const char KEY_FOCUS_ENG_BEST_STEP[];
    static const char KEY_RAW_DUMP_FLAG[];
    static const char KEY_PREVIEW_DUMP_RESOLUTION[];
    static const int  PREVIEW_DUMP_RESOLUTION_NORMAL;
    static const int  PREVIEW_DUMP_RESOLUTION_CROP;


    static const char EFFECT_SEPIA_BLUE[];
    static const char EFFECT_SEPIA_GREEN[];
    static const char  EFFECT_NASHVILLE[];
    static const char  EFFECT_HEFE[];
    static const char  EFFECT_VALENCIA[];
    static const char  EFFECT_XPROII[];
    static const char  EFFECT_LOFI[];
    static const char  EFFECT_SIERRA[];
    static const char  EFFECT_KELVIN[];
    static const char  EFFECT_WALDEN[];;
    static const char  EFFECT_F1977[];

    static const char WHITE_BALANCE_TUNGSTEN[];

    static const char ISO_SPEED_ENG[];
    static const char KEY_FOCUS_ENG_MODE[];
    static const char KEY_FOCUS_ENG_STEP[];
    static const char KEY_RAW_SAVE_MODE[];
    static const char KEY_RAW_PATH[];


    static const char KEY_FAST_CONTINUOUS_SHOT[];


    static const char KEY_VIDEO_HDR[];
    static const char KEY_VIDEO_HDR_MODE[];
    static const char VIDEO_HDR_MODE_IVHDR[];
    static const char VIDEO_HDR_MODE_MVHDR[];
    static const char VIDEO_HDR_MODE_ZVHDR[];
    static const char VIDEO_HDR_SIZE_DEVISOR[];


    static const char KEY_SINGLE_FRAME_CAPTURE_HDR_SUPPORTED[];


    static const char KEY_SUPPORT_MZAF_FEATURE[];



    static const char KEY_HDR_DETECTION_SUPPORTED[];



    static const char KEY_HDR_AUTO_MODE[];



    static const char KEY_HDR_MODE[];







    static const char HDR_MODE_OFF[];




    static const char HDR_MODE_ON[];






    static const char HDR_MODE_AUTO[];






    static const char HDR_MODE_VIDEO_ON[];







    static const char HDR_MODE_VIDEO_AUTO[];

    static const char KEY_MAX_NUM_DETECTED_OBJECT[];


    static const char KEY_HEARTBEAT_MONITOR[];
    static const char KEY_HEARTBEAT_MONITOR_SUPPORTED[];


    static const char KEY_CSHOT_INDICATOR[];


    static const char KEY_ENG_AE_ENABLE[];
    static const char KEY_ENG_PREVIEW_SHUTTER_SPEED[];
    static const char KEY_ENG_PREVIEW_SENSOR_GAIN[];
    static const char KEY_ENG_PREVIEW_ISP_GAIN[];
    static const char KEY_ENG_PREVIEW_AE_INDEX[];
    static const char KEY_ENG_PREVIEW_ISO[];
    static const char KEY_ENG_CAPTURE_SENSOR_GAIN[];
    static const char KEY_ENG_CAPTURE_ISP_GAIN[];
    static const char KEY_ENG_CAPTURE_SHUTTER_SPEED[];
    static const char KEY_ENG_CAPTURE_ISO[];
    static const char KEY_ENG_FLASH_DUTY_VALUE[];
    static const char KEY_ENG_FLASH_DUTY_MIN[];
    static const char KEY_ENG_FLASH_DUTY_MAX[];
    static const char KEY_ENG_ZSD_ENABLE[];
    static const char KEY_SENSOR_TYPE[];
    static const char KEY_ENG_PREVIEW_FPS[];
    static const char KEY_ENG_MSG[];
    static const int  KEY_ENG_FLASH_DUTY_DEFAULT_VALUE;
    static const int  KEY_ENG_FLASH_STEP_DEFAULT_VALUE;
    static const char KEY_ENG_FLASH_STEP_MIN[];
    static const char KEY_ENG_FLASH_STEP_MAX[];
    static const char KEY_ENG_FOCUS_FULLSCAN_FRAME_INTERVAL[];
    static const char KEY_ENG_FOCUS_FULLSCAN_FRAME_INTERVAL_MAX[];
    static const char KEY_ENG_FOCUS_FULLSCAN_FRAME_INTERVAL_MIN[];
    static const int  KEY_ENG_FOCUS_FULLSCAN_FRAME_INTERVAL_MAX_DEFAULT;
    static const int  KEY_ENG_FOCUS_FULLSCAN_FRAME_INTERVAL_MIN_DEFAULT;
    static const char KEY_ENG_FOCUS_FULLSCAN_DAC_STEP[];
    static const char KEY_ENG_PREVIEW_FRAME_INTERVAL_IN_US[];
    static const char KEY_ENG_PARAMETER1[];
    static const char KEY_ENG_PARAMETER2[];
    static const char KEY_ENG_PARAMETER3[];


    static const char KEY_ENG_RAW_OUTPUT_PORT[];
    static const int  KEY_ENG_RAW_IMGO;
    static const int  KEY_ENG_RAW_RRZO;


    static const char KEY_ENG_ISP_PROFILE[];
    static const int  KEY_ENG_ISP_PREVIEW;
    static const int  KEY_ENG_ISP_CAPTURE;
    static const int  KEY_ENG_ISP_VIDEO;

    static const char KEY_ENG_EV_VALUE[];
    static const char KEY_ENG_EVB_ENABLE[];

    static const char KEY_ENG_3ADB_FLASH_ENABLE[];

    static const char KEY_ENG_SAVE_SHADING_TABLE[];
    static const char KEY_ENG_SHADING_TABLE[];
    static const int KEY_ENG_SHADING_TABLE_AUTO;
    static const int KEY_ENG_SHADING_TABLE_LOW;
    static const int KEY_ENG_SHADING_TABLE_MIDDLE;
    static const int KEY_ENG_SHADING_TABLE_HIGH;
    static const int KEY_ENG_SHADING_TABLE_TSF;

    static const char KEY_VR_BUFFER_COUNT[];


    static const char KEY_ENG_EV_CALBRATION_OFFSET_VALUE[];


    static const char KEY_ENG_MFLL_SUPPORTED[];
    static const char KEY_ENG_MFLL_ENABLE[];
    static const char KEY_ENG_MFLL_PICTURE_COUNT[];


    static const char KEY_ENG_SENOSR_MODE_SLIM_VIDEO1_SUPPORTED[];
    static const char KEY_ENG_SENOSR_MODE_SLIM_VIDEO2_SUPPORTED[];


    static const char KEY_ENG_VIDEO_RAW_DUMP_RESIZE_TO_2M_SUPPORTED[];
    static const char KEY_ENG_VIDEO_RAW_DUMP_RESIZE_TO_4K2K_SUPPORTED[];
    static const char KEY_ENG_VIDEO_RAW_DUMP_CROP_CENTER_2M_SUPPORTED[];
    static const char KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_SUPPORTED[];
    static const char KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_ENABLE[];
    static const char KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_MIN[];
    static const char KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_MAX[];
    static const char KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_RANGE_LOW[];
    static const char KEY_ENG_VIDEO_RAW_DUMP_MANUAL_FRAME_RATE_RANGE_HIGH[];
    static const char KEY_ENG_VIDEO_RAW_DUMP_RESIZE[];
    static const char KEY_ENG_VIDEO_RAW_DUMP_SUPPORTED[];

    static const char KEY_ENG_MTK_AWB_SUPPORTED[];
    static const char KEY_ENG_SENSOR_AWB_SUPPORTED[];
    static const char KEY_ENG_MTK_AWB_ENABLE[];
    static const char KEY_ENG_SENSOR_AWB_ENABLE[];

    static const char KEY_ENG_MTK_SHADING_SUPPORTED[];
    static const char KEY_ENG_MTK_1to3_SHADING_SUPPORTED[];
    static const char KEY_ENG_SENSOR_SHADNING_SUPPORTED[];
    static const char KEY_ENG_MTK_SHADING_ENABLE[];
    static const char KEY_ENG_MTK_1to3_SHADING_ENABLE[];
    static const char KEY_ENG_SENSOR_SHADNING_ENABLE[];

    static const char KEY_ENG_MANUAL_MULTI_NR_SUPPORTED[];
    static const char KEY_ENG_MANUAL_MULTI_NR_ENABLE[];
    static const char KEY_ENG_MANUAL_MULTI_NR_TYPE[];
    static const char KEY_ENG_VIDEO_HDR_SUPPORTED[];
    static const char KEY_ENG_VIDEO_HDR_MODE[];
    static const char KEY_ENG_VIDEO_HDR_RATIO[];


    static const char KEY_HSVR_PRV_SIZE[];
    static const char KEY_SUPPORTED_HSVR_PRV_SIZE[];
    static const char KEY_HSVR_PRV_FPS[];
    static const char KEY_SUPPORTED_HSVR_PRV_FPS[];
    static const char KEY_HSVR_SIZE_FPS[];
    static const char KEY_SUPPORTED_HSVR_SIZE_FPS[];


    static const char KEY_MFB_MODE[];
    static const char KEY_MFB_MODE_MFLL[];
    static const char KEY_MFB_MODE_AIS[];


    static const char KEY_PIP_MAX_FRAME_RATE_ZSD_ON[];
    static const char KEY_PIP_MAX_FRAME_RATE_ZSD_OFF[];


    static const char KEY_DYNAMIC_FRAME_RATE[];
    static const char KEY_DYNAMIC_FRAME_RATE_SUPPORTED[];


    static const char KEY_STEREO_REFOCUS_MODE[];
    static const char KEY_STEREO_CAPTURE_MODE[];
    static const char KEY_STEREO_DEPTHAF_MODE[];
    static const char KEY_STEREO_DISTANCE_MODE[];
    static const char KEY_STEREO_PICTURE_SIZE[];
    static const char KEY_SUPPORTED_STEREO_PICTURE_SIZE[];
    static const char KEY_REFOCUS_PICTURE_SIZE[];
    static const char KEY_SUPPORTED_REFOCUS_PICTURE_SIZE[];
    static const char KEY_STEREO_PREVIEW_FRAME_RATE[];
    static const char KEY_STEREO_CAPTURE_FRAME_RATE[];
    static const char KEY_STEREO_SENSOR_INDEX_MAIN[];
    static const char KEY_STEREO_SENSOR_INDEX_MAIN2[];
    static const char KEY_STEREO_CAPTURE_SUPPORTED_MODULE[];

    static const char KEY_STEREO_VSDOF_MODE[];
    static const char KEY_STEREO_DOF_LEVEL[];
    static const char KEY_STEREO_SUPPORTED_DOF_LEVEL[];
    static const char KEY_STEREO_RESULT_DOF_LEVEL[];
    static const char KEY_STEREO_VSDOF_SUPPORTED_MODULE[];
    static const char KEY_STEREO_TOUCH_POSITION[];

    static const char KEY_STEREO_DENOISE_MODE[];
    static const char KEY_STEREO_DENOISE_SUPPORTED_MODULE[];

    static const char KEY_STEREO_3RDPARTY_MODE[];
    static const char KEY_STEREO_3RDPARTY_SUPPORTED_MODULE[];

    static const char KEY_STEREO_PREVIEW_ENABLE[];


    static const char KEY_DUALCAM_CAPTURE_MODE[];


    static const char KEY_REFOCUS_JPS_FILE_NAME[];


    static const char KEY_3DNR_MODE[];
    static const char KEY_3DNR_QUALITY_SUPPORTED[];

    static const char KEY_EIS_SUPPORTED_FRAMES[];
    static const char KEY_EIS25_MODE[];


    static const char KEY_ENG_MANUAL_SHUTTER_SPEED [];
    static const char KEY_ENG_MANUAL_SENSOR_GAIN[];


    static const char KEY_ENG_FLASH_CALIBRATION[];


    static const char KEY_ENG_SENOSR_MODE_SUPPORTED[];


    static const char KEY_GESTURE_SHOT[];
    static const char KEY_GESTURE_SHOT_SUPPORTED[];


    static const char KEY_NATIVE_PIP[];
    static const char KEY_NATIVE_PIP_SUPPORTED[];


    static const char KEY_PDAF[];
    static const char KEY_PDAF_SUPPORTED[];


    static const char KEY_FIRST_PREVIEW_FRAME_BLACK[];


    static const char KEY_DNG_SUPPORTED[];


    static const char KEY_DISPLAY_ROTATION_SUPPORTED[];
    static const char KEY_PANEL_SIZE[];


    static const char KEY_IS_SUPPORT_MZAF[];
    static const char KEY_MZAF_ENABLE[];


    static const char KEY_POST_VIEW_FMT[];

public:
    static const char ON[];
    static const char OFF[];

    static const char REAR[];
    static const char FRONT[];
};

};

#endif
