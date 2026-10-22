/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */


























/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/






























































#ifndef _CFG_AUDIO_FILE_H
#define _CFG_AUDIO_FILE_H

#define MTK_AUDIO_BLOUD_CUSTOMPARAMETER_V5 1

#define CUSTOM_VOLUME_STEP (7)
#define AUDIO_MAX_VOLUME_STEP (15)

#define NB_FIR_NUM (45)
#define NB_FIR_INDEX_NUM   (6)
#define SPEECH_COMMON_NUM (12)
#define SPEECH_PARA_MODE_NUM     (8)
#define SPEECH_PARA_NUM                (16)
#define AUDIO_EQ_PARAM_NUM         (8)

#define WB_FIR_NUM (90)
#define WB_FIR_INDEX_NUM   (6)

#define HD_REC_MODE_INDEX_NUM   (30)
#define HD_REC_FIR_INDEX_NUM    (16)

#define VOIP_INDEX_NUM   (4)


#define VOICE_FOLDER_NAME_LEN_MAX 32
#define VOICE_AP_NUM_MAX 16
#define VOICE_LANGUAGE_NUM_MAX 8
#define VOICE_CMDS_NUM_MAX 8
#define VOICE_CMDS_PER_LAN_NUM_MAX 32
#define VOICE_RECOG_FEATURE_NUM_MAX 8
#define VOICE_RECOG_PARAM_NUM_MAX 32

typedef enum
{
    VOL_NORMAL   = 0 ,
    VOL_HEADSET      ,
    VOL_HANDFREE     ,
    MAX_VOL_CATE
} volume_category_enum;

typedef enum
{
    VOL_TYPE_TON  = 0 ,
    VOL_TYPE_KEY      ,
    VOL_TYPE_MIC      ,
    VOL_TYPE_FMR      ,
    VOL_TYPE_SPH      ,
    VOL_TYPE_SID	    ,
    VOL_TYPE_MEDIA    ,
    MAX_VOL_TYPE
} volume_type_enum;


enum VolumeType {
    VER1_VOL_TYPE_RING = 0,
    VER1_VOL_TYPE_SIP,
    VER1_VOL_TYPE_MIC,
    VER1_VOL_TYPE_FM,
    VER1_VOL_TYPE_SPH,
    VER1_VOL_TYPE_SPH2,
    VER1_VOL_TYPE_SID,
    VER1_VOL_TYPE_MEDIA,
    VER1_VOL_TYPE_MATV,
    VER1_NUM_OF_VOL_TYPE
};

enum VolumeMode {
    VOLUME_NORMAL_MODE = 0,
    VOLUME_HEADSET_MODE,
    VOLUME_SPEAKER_MODE,
    VOLUME_HEADSET_SPEAKER_MODE,
    NUM_OF_VOL_MODE
};

enum VOLUME_NORMAL_TYPE {
    NORMAL_AUDIO_BUFFER = 0,
    NORMAL_FM_RECORD_A,
    NORMAL_FM_RECORD_D,
    NORMAL_SIP_AUDIO_BUFFER,
    NORMAL_RSERVED_2,
    NORMAL_RSERVED_3,
    NORMAL_VOLUME_TYPE_MAX
};

enum VOLUME_HEADSET_TYPE {
    HEADSET_AUDIO_BUFFER = 0,
    HEADSET_FM_RECORD_A,
    HEADSET_FM_RECORD_D,
    HEADSET_SIP_AUDIO_BUFFER,
    HEADSET_RSERVED_2,
    HEADSET_RSERVED_3,
    HEADSET_VOLUME_TYPE_MAX
};

enum VOLUME_SPEAKER_TYPE {
    SPEAKER_AMP = 0,
    SPEAKER_FM_RECORD_A,
    SPEAKER_FM_RECORD_D,
    SPEAKER_SIP_AUDIO_BUFFER,
    SPEAKER_RSERVED_2,
    SPEAKER_RSERVED_3,
    SPEAKER_VOLUME_TYPE_MAX
};

enum VOLUME_HEADSET_SPEAKER_TYPE {
    HEADSET_SPEAKER_AUDIO_BUFFER = 0,
    HEADSET_SPEAKER_AMP,
    HEADSET_SPEAKER_IV_BUFFER,
    HEADSET_SPEAKER_FM_RECORD_A,
    HEADSET_SPEAKER_FM_RECORD_D,
    HEADSET_SPEAKER_SIP_AUDIO_BUFFER,
    HEADSET_SPEAKER_RSERVED_2,
    HEADSET_SPEAKER_RSERVED_3,
    HEADSET_SPEAKER_VOLUME_TYPE_MAX
};


enum VOLUME_EXTAMP_TYPE {
    VOLUME_IV_BUFFER_EXTAMP = 0,
    VOLUME_AUDIO_BUFFER_EXTAMP,
    VOLUME_EXTAMP,
    VOLUME_EXTAMP_RSERVED_1,
    VOLUME_EXTAMP_RSERVED_2,
    VOLUME_EXTAMP_RSERVED_3,
    EXTAMP_VOLUME_TYPE_MAX
};

#define     NUM_ABF_PARAM 44
#define     NUM_ABFWB_PARAM 76


typedef struct _AUDIO_CUSTOM_EXTRA_PARAM_STRUCT
{

	unsigned short ABF_para[NUM_ABF_PARAM + NUM_ABFWB_PARAM];
	unsigned short ABF_para_LoudSPK[NUM_ABF_PARAM + NUM_ABFWB_PARAM];
	unsigned short ABF_para_VR[NUM_ABFWB_PARAM];
	unsigned short ABF_para_VOIP[NUM_ABFWB_PARAM];
	unsigned short ABF_para_VOIP_LoudSPK[NUM_ABFWB_PARAM];
} AUDIO_CUSTOM_EXTRA_PARAM_STRUCT;


#define CFG_FILE_SPEECH_DUAL_MIC_SIZE    sizeof(AUDIO_CUSTOM_EXTRA_PARAM_STRUCT)
#define CFG_FILE_SPEECH_DUAL_MIC_TOTAL   1

#define NUM_ANC_PARAM 60

typedef struct _AUDIO_ANC_CUSTOM_PARAM_STRUCT
{
   unsigned short ANC_para[NUM_ANC_PARAM];
   unsigned short ANC_apply;
   unsigned short ANC_log;
   unsigned short ANC_log_downsample;
   unsigned char ANC_dl_pga;
} AUDIO_ANC_CUSTOM_PARAM_STRUCT;

#define CFG_FILE_SPEECH_ANC_SIZE    sizeof(AUDIO_ANC_CUSTOM_PARAM_STRUCT)
#define CFG_FILE_SPEECH_ANC_TOTAL 1

typedef struct _AUDIO_CUSTOM_MAGI_CONFERENCE_STRUCT
{
   unsigned short sph_voice_tracking_mode_para[16];
   unsigned short sph_voice_tracking_mode_wb_para[16];
} AUDIO_CUSTOM_MAGI_CONFERENCE_STRUCT;

#define CFG_FILE_SPEECH_MAGI_CONFERENCE_SIZE    sizeof(AUDIO_CUSTOM_MAGI_CONFERENCE_STRUCT)
#define CFG_FILE_SPEECH_MAGI_CONFERENCE_TOTAL 1

typedef struct _AUDIO_CUSTOM_HAC_PARAM_STRUCT
{

    unsigned short speech_hac_mode_nb_para[16];

    unsigned short speech_hac_mode_wb_para[16];

    short sph_hac_in_fir[45];

    short sph_hac_out_fir[45];


    short sph_hac_wb_in_fir[90];

    short sph_hac_wb_out_fir[90];

    unsigned char audiovolume_mic_hac[AUDIO_MAX_VOLUME_STEP];

    unsigned char audiovolume_sph_hac[AUDIO_MAX_VOLUME_STEP];

    unsigned char audiovolume_sid_hac[AUDIO_MAX_VOLUME_STEP];

} AUDIO_CUSTOM_HAC_PARAM_STRUCT;

#define CFG_FILE_SPEECH_HAC_PARAM_SIZE    sizeof(AUDIO_CUSTOM_HAC_PARAM_STRUCT)
#define CFG_FILE_SPEECH_HAC_PARAM_TOTAL 1

typedef struct _AUDIO_CUSTOM_SPEECH_LPBK_PARAM_STRUCT
{

    unsigned short lpbk_speech_mode_nb_para[3][16];

} AUDIO_CUSTOM_SPEECH_LPBK_PARAM_STRUCT;

#define CFG_FILE_SPEECH_LPBK_PARAM_SIZE    sizeof(AUDIO_CUSTOM_SPEECH_LPBK_PARAM_STRUCT)
#define CFG_FILE_SPEECH_LPBK_PARAM_TOTAL 1

typedef struct _AUDIO_CUSTOM_AUDIO_FUNC_SWITCH_PARAM_STRUCT
{

    unsigned short vmlog_dump_config;
    unsigned short bgs_dump_enable;

    unsigned short cust_xml_enable;

} AUDIO_CUSTOM_AUDIO_FUNC_SWITCH_PARAM_STRUCT;

#define CFG_FILE_AUDIO_FUNC_SWITCH_PARAM_SIZE    sizeof(AUDIO_CUSTOM_AUDIO_FUNC_SWITCH_PARAM_STRUCT)
#define CFG_FILE_AUDIO_FUNC_SWITCH_PARAM_TOTAL 1
typedef struct _AUDIO_CUSTOM_PARAM_STRUCT
{

    unsigned char volume[MAX_VOL_CATE][MAX_VOL_TYPE];

    unsigned short speech_common_para[SPEECH_COMMON_NUM];
    unsigned short speech_mode_para[SPEECH_PARA_MODE_NUM][SPEECH_PARA_NUM];
    unsigned short speech_volume_para[4];

    unsigned short debug_info[16];

    short          sph_in_fir[NB_FIR_INDEX_NUM][NB_FIR_NUM];

    short          sph_out_fir[NB_FIR_INDEX_NUM][NB_FIR_NUM];

    unsigned short Digi_DL_Speech;

    unsigned short Digi_Microphone;

    unsigned short FM_Record_Volume;

    unsigned short Bluetooth_Sync_Type;
    unsigned short Bluetooth_Sync_Length;
    unsigned short bt_pcm_in_vol;
    unsigned short bt_pcm_out_vol;
    unsigned short user_mode;

    unsigned short uSupportVM;
    unsigned short uAutoVM;

    unsigned short uMicbiasVolt;

} AUDIO_CUSTOM_PARAM_STRUCT;

#define CFG_FILE_SPEECH_REC_SIZE        sizeof(AUDIO_CUSTOM_PARAM_STRUCT)
#define CFG_FILE_SPEECH_REC_TOTAL   1

typedef struct _AUDIO_CUSTOM_WB_A2M_PARAM_STRUCT_
{

    unsigned short speech_mode_wb_para[SPEECH_PARA_MODE_NUM][SPEECH_PARA_NUM];

    short          sph_wb_fir[WB_FIR_INDEX_NUM][WB_FIR_NUM];

    short          input_out_fir_flag;
} AUDIO_CUSTOM_WB_A2M_PARAM_STRUCT;

typedef struct _AUDIO_CUSTOM_WB_PARAM_STRUCT
{

    unsigned short speech_mode_wb_para[SPEECH_PARA_MODE_NUM][SPEECH_PARA_NUM];

    short          sph_wb_in_fir[WB_FIR_INDEX_NUM][WB_FIR_NUM];

    short          sph_wb_out_fir[WB_FIR_INDEX_NUM][WB_FIR_NUM];
} AUDIO_CUSTOM_WB_PARAM_STRUCT;

#define CFG_FILE_WB_SPEECH_REC_SIZE        sizeof(AUDIO_CUSTOM_WB_PARAM_STRUCT)
#define CFG_FILE_WB_SPEECH_REC_TOTAL   1

#if defined(MTK_AUDIO_BLOUD_CUSTOMPARAMETER_V5)

typedef struct _AUDIO_ACF_V5F_PARAM
{
    unsigned int bes_loudness_L_hpf_fc;
    unsigned int bes_loudness_L_hpf_order;
    unsigned int bes_loudness_L_lpf_fc;
    unsigned int bes_loudness_L_lpf_order;
    unsigned int bes_loudness_L_bpf_fc[8];
    unsigned int bes_loudness_L_bpf_bw[8];
    int          bes_loudness_L_bpf_gain[8];
    unsigned int bes_loudness_R_hpf_fc;
    unsigned int bes_loudness_R_hpf_order;
    unsigned int bes_loudness_R_lpf_fc;
    unsigned int bes_loudness_R_lpf_order;
    unsigned int bes_loudness_R_bpf_fc[8];
    unsigned int bes_loudness_R_bpf_bw[8];
    int          bes_loudness_R_bpf_gain[8];

}AUDIO_ACF_V5F_PARAM;

typedef struct _AUDIO_ACF_V5VIBSPK_PARAM
{
    unsigned int bes_loudness_bpf_coeff[2][6][3];

}AUDIO_ACF_V5VIBSPK_PARAM;


typedef struct _AUDIO_ACF_CUSTOM_PARAM_STRUCT
{

    union{
        AUDIO_ACF_V5F_PARAM V5F;
        AUDIO_ACF_V5VIBSPK_PARAM V5ViVSPK;
    }bes_loudness_f_param;
    unsigned int bes_loudness_Sep_LR_Filter;
    unsigned int bes_loudness_WS_Gain_Max;
    unsigned int bes_loudness_WS_Gain_Min;
    unsigned int bes_loudness_Filter_First;
    unsigned int bes_loudness_Num_Bands;
    unsigned int bes_loudness_Flt_Bank_Order;
    unsigned int bes_loudness_Cross_Freq[7];
    int DRC_Th[8][5];
    int DRC_Gn[8][5];
    int SB_Gn[8];
    unsigned int SB_Mode[8];
    unsigned int DRC_Delay;
    unsigned int Att_Time[8][6];
    unsigned int Rel_Time[8][6];
    int Hyst_Th[8][6];
    int Lim_Th;
    int Lim_Gn;
    unsigned int Lim_Const;
    unsigned int Lim_Delay;
    int SWIPRev;
} AUDIO_ACF_CUSTOM_PARAM_STRUCT;
#if 0
typedef struct _AUDIO_ACF_CUSTOM_PARAM_STRUCT
{
    unsigned int bes_loudness_hsf_coeff_L[2][9][5];
    unsigned int bes_loudness_bpf_coeff_L[8][6][3];
    unsigned int bes_loudness_lpf_coeff_L[6][3];

    unsigned int bes_loudness_hsf_coeff_R[2][9][5];
    unsigned int bes_loudness_bpf_coeff_R[8][6][3];
    unsigned int bes_loudness_lpf_coeff_R[6][3];

    unsigned int bes_loudness_WS_Gain_Max;
    unsigned int bes_loudness_WS_Gain_Min;
    unsigned int bes_loudness_Filter_First;
    unsigned int bes_loudness_Sep_LR_Filter;

    unsigned int bes_loudness_Num_Bands;
    unsigned int bes_loudness_Flt_Bank_Order;
    unsigned int bes_loudness_Cross_Freq[7];
    int bes_loudness_DRC_Th[8][5];
    int bes_loudness_DRC_Gn[8][5];
    int bes_loudness_SB_Gn[8];
    unsigned int bes_loudness_SB_Mode[8];

    unsigned int bes_loudness_DRC_Delay;
    unsigned int bes_loudness_Att_Time[8][6];
    unsigned int bes_loudness_Rel_Time[8][6];
    int bes_loudness_Hyst_Th[8][6];
    int bes_loudness_Lim_Th;
    int bes_loudness_Lim_Gn;
    unsigned int bes_loudness_Lim_Const;
    unsigned int bes_loudness_Lim_Delay;










} AUDIO_ACF_CUSTOM_PARAM_STRUCT;
#endif
#elif defined(MTK_AUDIO_BLOUD_CUSTOMPARAMETER_V4)
typedef struct _AUDIO_ACF_CUSTOM_PARAM_STRUCT
{
    unsigned int bes_loudness_hsf_coeff[2][9][5];
    unsigned int bes_loudness_bpf_coeff[8][6][3];

    unsigned int bes_loudness_lpf_coeff[6][3];
    unsigned int bes_loudness_WS_Gain_Max;
    unsigned int bes_loudness_WS_Gain_Min;
    unsigned int bes_loudness_Filter_First;
	unsigned int bes_loudness_Att_Time;
	unsigned int bes_loudness_Rel_Time;
    char bes_loudness_Gain_Map_In[5];
    char bes_loudness_Gain_Map_Out[5];
} AUDIO_ACF_CUSTOM_PARAM_STRUCT;
#else
typedef struct _AUDIO_ACF_CUSTOM_PARAM_STRUCT
{


    unsigned int bes_loudness_hsf_coeff[9][4];


    unsigned int bes_loudness_bpf_coeff[4][6][3];
    unsigned int bes_loudness_DRC_Forget_Table[9][2];
    unsigned int bes_loudness_WS_Gain_Max;
    unsigned int bes_loudness_WS_Gain_Min;
    unsigned int bes_loudness_Filter_First;
    char bes_loudness_Gain_Map_In[5];
    char bes_loudness_Gain_Map_Out[5];

} AUDIO_ACF_CUSTOM_PARAM_STRUCT;
#endif


#define CFG_FILE_AUDIO_COMPFLT_REC_SIZE        sizeof(AUDIO_ACF_CUSTOM_PARAM_STRUCT)
#define CFG_FILE_AUDIO_COMPFLT_REC_TOTAL   1
#define CFG_FILE_HEADPHONE_COMPFLT_REC_TOTAL   1
#define CFG_FILE_VIBSPK_COMPFLT_REC_TOTAL   1
#define CFG_FILE_AUDIOSUB_COMPFLT_REC_TOTAL   1
#define CFG_FILE_AUDIOSUB_COMPFLT_REC_TOTAL   1
#define CFG_FILE_MUSICDRC_COMPFLT_REC_TOTAL   1
#define CFG_FILE_RINGTONEDRC_COMPFLT_REC_TOTAL   1


typedef struct _AUDIO_EFFECT_CUSTOM_PARAM_STRUCT
{

    int bsrd_level;
    unsigned int Distance1;
    unsigned int Distance2;
    int bsrd_band_select;


    unsigned int bass_CutoffFreq;
    int bass_IsVB;


    short Normal_Gain_dB_level[AUDIO_EQ_PARAM_NUM];
    short Dance_Gain_dB_level[AUDIO_EQ_PARAM_NUM];
    short Bass_Gain_dB_level[AUDIO_EQ_PARAM_NUM];
    short Classical_Gain_dB_level[AUDIO_EQ_PARAM_NUM];
    short Treble_Gain_dB_level[AUDIO_EQ_PARAM_NUM];
    short Party_Gain_dB_level[AUDIO_EQ_PARAM_NUM];
    short Pop_Gain_dB_level[AUDIO_EQ_PARAM_NUM];
    short Rock_Gain_dB_level[AUDIO_EQ_PARAM_NUM];


    int LoudEnhancemode;


    int Time_TD_FD;
    int Time_TS_Ratio;

} AUDIO_EFFECT_CUSTOM_PARAM_STRUCT;

#define CFG_FILE_AUDIO_EFFECT_REC_SIZE        sizeof(AUDIO_EFFECT_CUSTOM_PARAM_STRUCT)
#define CFG_FILE_AUDIO_EFFECT_REC_TOTAL   1

typedef struct _AUDIO_PARAM_MED_STRUCT
{
    short speech_input_FIR_coeffs[SPEECH_PARA_MODE_NUM][NB_FIR_NUM];
    short speech_output_FIR_coeffs[SPEECH_PARA_MODE_NUM][NB_FIR_INDEX_NUM][NB_FIR_NUM];
    short select_FIR_output_index[SPEECH_PARA_MODE_NUM];
    short select_FIR_intput_index[SPEECH_PARA_MODE_NUM];
    short speech_mode_para[SPEECH_PARA_MODE_NUM][SPEECH_PARA_NUM];
} AUDIO_PARAM_MED_STRUCT;

#define CFG_FILE_AUDIO_PARAM_MED_REC_SIZE        sizeof(AUDIO_PARAM_MED_STRUCT)
#define CFG_FILE_AUDIO_PARAM_MED_REC_TOTAL   1


typedef struct _AUDIO_VOLUME_CUSTOM_STRUCT
{
    unsigned char audiovolume_ring[MAX_VOL_CATE][CUSTOM_VOLUME_STEP];
    unsigned char audiovolume_key[MAX_VOL_CATE][CUSTOM_VOLUME_STEP];
    unsigned char audiovolume_mic[MAX_VOL_CATE][CUSTOM_VOLUME_STEP];
    unsigned char audiovolume_fmr[MAX_VOL_CATE][CUSTOM_VOLUME_STEP];
    unsigned char audiovolume_sph[MAX_VOL_CATE][CUSTOM_VOLUME_STEP];
    unsigned char audiovolume_sid[MAX_VOL_CATE][CUSTOM_VOLUME_STEP];
    unsigned char audiovolume_media[MAX_VOL_CATE][CUSTOM_VOLUME_STEP];
    unsigned char audiovolume_matv[MAX_VOL_CATE][CUSTOM_VOLUME_STEP];
} AUDIO_VOLUME_CUSTOM_STRUCT;

#define CFG_FILE_AUDIO_VOLUME_CUSTOM_REC_SIZE        sizeof(AUDIO_VOLUME_CUSTOM_STRUCT)
#define CFG_FILE_AUDIO_VOLUME_CUSTOM_REC_TOTAL   1

typedef struct _AUDIO_VER1_CUSTOM_VOLUME_STRUCT {
    unsigned char audiovolume_ring[NUM_OF_VOL_MODE][AUDIO_MAX_VOLUME_STEP];
    unsigned char audiovolume_sip[NUM_OF_VOL_MODE][AUDIO_MAX_VOLUME_STEP];
    unsigned char audiovolume_mic[NUM_OF_VOL_MODE][AUDIO_MAX_VOLUME_STEP];
    unsigned char audiovolume_fm[NUM_OF_VOL_MODE][AUDIO_MAX_VOLUME_STEP];
    unsigned char audiovolume_sph[NUM_OF_VOL_MODE][AUDIO_MAX_VOLUME_STEP];
    unsigned char audiovolume_sph2[NUM_OF_VOL_MODE][AUDIO_MAX_VOLUME_STEP];
    unsigned char audiovolume_sid[NUM_OF_VOL_MODE][AUDIO_MAX_VOLUME_STEP];
    unsigned char audiovolume_media[NUM_OF_VOL_MODE][AUDIO_MAX_VOLUME_STEP];
    unsigned char audiovolume_matv[NUM_OF_VOL_MODE][AUDIO_MAX_VOLUME_STEP];

    unsigned char normalaudiovolume[NORMAL_VOLUME_TYPE_MAX];
    unsigned char headsetaudiovolume[HEADSET_VOLUME_TYPE_MAX];
    unsigned char speakeraudiovolume[SPEAKER_VOLUME_TYPE_MAX];
    unsigned char headsetspeakeraudiovolume[HEADSET_SPEAKER_VOLUME_TYPE_MAX];
    unsigned char extampaudiovolume[EXTAMP_VOLUME_TYPE_MAX];

    unsigned char audiovolume_level[VER1_NUM_OF_VOL_TYPE];
} AUDIO_VER1_CUSTOM_VOLUME_STRUCT;

#define CFG_FILE_AUDIO_VER1_VOLUME_CUSTOM_REC_SIZE        sizeof(AUDIO_VER1_CUSTOM_VOLUME_STRUCT)
#define CFG_FILE_AUDIO_VER1_VOLUME_CUSTOM_REC_TOTAL   1






#define AUDIO_MAX_AMP_CONTROL_POINTS  (10)
#define AUDIO_MAX_GAIN_TABLE_STEP     (18)
#define AUDIO_MAX_MIC_GAIN_NUMS       (32)

typedef enum  {
	AUDIO_GAIN_DEFAULT 		    =-1,
	AUDIO_GAIN_VOICE_CALL		= 0,
	AUDIO_GAIN_SYSTEM			= 1,
	AUDIO_GAIN_RING			    = 2,
	AUDIO_GAIN_MUSIC			= 3,
	AUDIO_GAIN_ALARM			= 4,
	AUDIO_GAIN_NOTIFICATION	    = 5,
	AUDIO_GAIN_BLUETOOTH_SCO	= 6,
	AUDIO_GAIN_ENFORCED_AUDIBLE = 7,
	AUDIO_GAIN_DTMF			    = 8,
	AUDIO_GAIN_TTS 			    = 9,
	AUDIO_GAIN_FM				= 10,
	AUDIO_GAIN_MATV				= 11,
	AUDIO_GAIN_MAX_STREAM       = 11,
    NUM_AUDIO_GAIN_TYPES
}audio_gain_type;


typedef enum {
	GAIN_OUTPUT_EARPIECE = 0,
	GAIN_OUTPUT_HEADSET  = 1,
	GAIN_OUTPUT_SPEAKER  = 2,
	GAIN_OUTPUT_DOCK     = 3,
	NUM_GAIN_OUTPUT_DEVICES = 4
}output_gain_device;


typedef enum {
    GAIN_IDLE_RECORD_MIC =0,
    GAIN_IDLE_RECORD_HEADSET ,
    GAIN_VOICE_REC_MIC,
    GAIN_VOICE_REC_HEADSET,
    GAIN_VIDEO_REC_MIC,
    GAIN_VIDEO_REC_HEADSET,
    GAIN_INCALL_NB_ECEIVER,
    GAIN_INCALL_NB_HEADSET,
    GAIN_INCALL_NB_SPEAKER,
    GAIN_INCALL_WB_ECEIVER,
    GAIN_INCALL_WB_HEADSET,
    GAIN_INCALL_WB_SPEAKER,
    GAIN_VOIP_RECEIVER,
    GAIN_VOIP_HEADSET,
    GAIN_VOIP_SPEAKER,
    GAIN_TTY_DEVICE,
    GAIN_LEVEL_SHIFT,
    GAIN_ANALOG_PLAY,
    GAIN_VOICE_UNLOCK_MIC,
    GAIN_VOICE_UNLOCK_HEADSET,
    GAIN_RESERVED1_MIC,
    GAIN_RESERVED1_HEADSET,
    GAIN_RESERVED2_MIC,
    GAIN_RESERVED2_HEADSET,
    NUM_MIC_GAINS
}microphone_device_gain;



typedef struct _STREAM_ITEM_GAIN_STRUCT
{
     unsigned char digital[AUDIO_MAX_GAIN_TABLE_STEP];
     unsigned char analog;
     unsigned char amp[AUDIO_MAX_AMP_CONTROL_POINTS];

}STREAM_ITEM_GAIN;

typedef struct _STREAM_GAIN_STRUCT
{
    STREAM_ITEM_GAIN stream[NUM_GAIN_OUTPUT_DEVICES];

}STREAM_GAIN;


typedef struct _SPEECH_ITEM_GAIN_STRUCT
{
     unsigned char digital;
     unsigned char analog;
     unsigned char amp[AUDIO_MAX_AMP_CONTROL_POINTS];

}SPEECH_ITEM_GAIN;

typedef struct _SPEECH_GAIN_STRUCT
{
    SPEECH_ITEM_GAIN speech[NUM_GAIN_OUTPUT_DEVICES][AUDIO_MAX_GAIN_TABLE_STEP];

}SPEECH_GAIN;



typedef struct _SIDETONE_GAIN_STRUCT
{
    unsigned char sidetone[NUM_GAIN_OUTPUT_DEVICES];
} SIDETONE_GAIN;



typedef struct _MIC_ITEM_GAIN_STRUCT
{
     unsigned char digital;
     unsigned char analog;
}MIC_ITEM_GAIN;

typedef struct _MICROPHONE_GAIN_STRUCT
{
    MIC_ITEM_GAIN mic[AUDIO_MAX_MIC_GAIN_NUMS];

} MIC_GAIN;

typedef struct _AUDIO_CUSTOM_GAIN_TABLE {
    STREAM_GAIN    voiceCall;
    STREAM_GAIN    system;
    STREAM_GAIN    ring;
    STREAM_GAIN    music;
    STREAM_GAIN    alarm;
    STREAM_GAIN    notification;
    STREAM_GAIN    blueToothSco;
    STREAM_GAIN    enforceAudible;
    STREAM_GAIN    dtmf;
    STREAM_GAIN    tts;
    STREAM_GAIN    fm;
    STREAM_GAIN    matv;
    SPEECH_GAIN    speechNB;
    SPEECH_GAIN    speechWB;
    SIDETONE_GAIN  sideToneNB;
    SIDETONE_GAIN  sideToneWB;
    MIC_GAIN       mic;
} AUDIO_GAIN_TABLE_STRUCT;

#define CFG_FILE_AUDIO_GAIN_TABLE_CUSTOM_REC_SIZE        sizeof(AUDIO_GAIN_TABLE_STRUCT)
#define CFG_FILE_AUDIO_GAIN_TABLE_CUSTOM_REC_TOTAL   1

typedef struct _AUDIO_CUSTOM_BT_GAIN {
    STREAM_GAIN    blueToothNrec;
} AUDIO_BT_GAIN_STRUCT;

#define CFG_FILE_AUDIO_BT_GAIN_CUSTOM_SIZE        sizeof(AUDIO_BT_GAIN_STRUCT)
#define CFG_FILE_AUDIO_BT_GAIN_CUSTOM_TOTAL   1



#define SPC_MAX_NUM_RECORD_SPH_MODE HD_REC_MODE_INDEX_NUM
#define SPC_MAX_NUM_RECORD_INPUT_FIR HD_REC_FIR_INDEX_NUM
typedef struct _AUDIO_HD_RECORD_PARAM_STRUCT
{

    unsigned short hd_rec_mode_num;
    unsigned short hd_rec_fir_num;


    unsigned short hd_rec_speech_mode_para[SPC_MAX_NUM_RECORD_SPH_MODE][SPEECH_PARA_NUM];


    short          hd_rec_fir[SPC_MAX_NUM_RECORD_INPUT_FIR][WB_FIR_NUM];


    unsigned short hd_rec_map_to_fir_for_ch1[SPC_MAX_NUM_RECORD_SPH_MODE];
    unsigned short hd_rec_map_to_fir_for_ch2[SPC_MAX_NUM_RECORD_SPH_MODE];


    unsigned char hd_rec_map_to_dev_mode[SPC_MAX_NUM_RECORD_SPH_MODE];


    unsigned char hd_rec_map_to_input_src[SPC_MAX_NUM_RECORD_SPH_MODE];


    unsigned char hd_rec_map_to_stereo_flag[SPC_MAX_NUM_RECORD_SPH_MODE];

} AUDIO_HD_RECORD_PARAM_STRUCT;


#define CFG_FILE_AUDIO_HD_REC_PAR_SIZE   sizeof(AUDIO_HD_RECORD_PARAM_STRUCT)
#define CFG_FILE_AUDIO_HD_REC_PAR_TOTAL  1



#define MAX_HD_REC_SCENES 10

enum HD_REC_DEVICE_SOURCE_T
{
    HD_REC_DEVICE_SOURCE_HANDSET     = 0,
    HD_REC_DEVICE_SOURCE_HEADSET     = 1,
    HD_REC_DEVICE_SOURCE_BT_EARPHONE = 2,
    NUM_HD_REC_DEVICE_SOURCE
};

typedef struct
{
	unsigned char num_voice_recognition_scenes;
    unsigned char num_voice_rec_scenes;
    unsigned char num_video_rec_scenes;
	unsigned char num_voice_unlock_scenes;
	unsigned char num_customization_scenes;
    unsigned char scene_table[MAX_HD_REC_SCENES][NUM_HD_REC_DEVICE_SOURCE];
	unsigned char scene_name[MAX_HD_REC_SCENES][10];
} AUDIO_HD_RECORD_SCENE_TABLE_STRUCT;


#define CFG_FILE_AUDIO_HD_REC_SCENE_TABLE_SIZE   sizeof(AUDIO_HD_RECORD_SCENE_TABLE_STRUCT)
#define CFG_FILE_AUDIO_HD_REC_SCENE_TABLE_TOTAL  1






typedef struct _VOICE_RECOGNITION_PARAM_STRUCT
{

	  unsigned char ap_num;
    unsigned char language_num;
    unsigned char language_folder[VOICE_LANGUAGE_NUM_MAX][VOICE_FOLDER_NAME_LEN_MAX];
    unsigned char cmd_num[VOICE_LANGUAGE_NUM_MAX];
    unsigned char ap_support_info[VOICE_AP_NUM_MAX][VOICE_LANGUAGE_NUM_MAX][VOICE_CMDS_NUM_MAX];
    unsigned char cust_param[VOICE_RECOG_FEATURE_NUM_MAX][VOICE_RECOG_PARAM_NUM_MAX];

} VOICE_RECOGNITION_PARAM_STRUCT;


#define CFG_FILE_VOICE_RECOGNIZE_PAR_SIZE   sizeof(VOICE_RECOGNITION_PARAM_STRUCT)
#define CFG_FILE_VOICE_RECOGNIZE_PAR_TOTAL  1


typedef struct
{
	unsigned int u32EnableFlg;

}AUDIO_AUDENH_CONTROL_OPTION_STRUCT;

#define CFG_FILE_AUDIO_AUDENH_CONTROL_OPTION_PAR_SIZE   sizeof(AUDIO_AUDENH_CONTROL_OPTION_STRUCT)
#define CFG_FILE_AUDIO_AUDENH_CONTROL_OPTION_PAR_TOTAL  1


typedef struct _AUDIO_BUFFER_DC_CALIBRATION_STRUCT
{
    unsigned short cali_flag;
	unsigned short cali_val_hp_left;
    unsigned short cali_val_hp_right;
    unsigned short cali_val_speaker;
} AUDIO_BUFFER_DC_CALIBRATION_STRUCT;


#define CFG_FILE_AUDIO_BUFFER_DC_CALIBRATION_PAR_SIZE   sizeof(AUDIO_BUFFER_DC_CALIBRATION_STRUCT)
#define CFG_FILE_AUDIO_BUFFER_DC_CALIBRATION_PAR_TOTAL  1


enum AUDIO_VOIP_DEVICE_TYPE {
	AUDIO_VOIP_DEVICE_NORMAL	= 0,
	AUDIO_VOIP_DEVICE_SPEAKER	= 1,
	AUDIO_VOIP_DEVICE_HEADSET	= 2,
	AUDIO_VOIP_DEVICE_BT		= 3,
    NUM_AUDIO_VOIP_DEVICE		= VOIP_INDEX_NUM
};

typedef struct _AUDIO_VOIP_PARAM_STRUCT
{

    unsigned short speech_common_para[SPEECH_COMMON_NUM];
    unsigned short speech_mode_para[VOIP_INDEX_NUM][SPEECH_PARA_NUM];


    short	in_fir[VOIP_INDEX_NUM][WB_FIR_NUM];

    short	out_fir[VOIP_INDEX_NUM][WB_FIR_NUM];

} AUDIO_VOIP_PARAM_STRUCT;


#define CFG_FILE_AUDIO_VOIP_PAR_SIZE   sizeof(AUDIO_VOIP_PARAM_STRUCT)
#define CFG_FILE_AUDIO_VOIP_PAR_TOTAL  1

enum AUDIO_HFP_DEVICE_TYPE {
	AUDIO_HFP_DEVICE_NORMAL	= 0,
	AUDIO_HFP_DEVICE_SPEAKER	= 1,
	AUDIO_HFP_DEVICE_HEADSET	= 2,
	AUDIO_HFP_DEVICE_RESERVED		= 3,
    NUM_AUDIO_HFP_DEVICE
};

typedef struct _AUDIO_HFP_PARAM_STRUCT
{

    unsigned short speech_common_para[SPEECH_COMMON_NUM];
    unsigned short speech_mode_para[NUM_AUDIO_HFP_DEVICE][SPEECH_PARA_NUM];


    short	in_fir[NUM_AUDIO_HFP_DEVICE][WB_FIR_NUM];

    short	out_fir[NUM_AUDIO_HFP_DEVICE][WB_FIR_NUM];

} AUDIO_HFP_PARAM_STRUCT;


#define CFG_FILE_AUDIO_HFP_PAR_SIZE   sizeof(AUDIO_HFP_PARAM_STRUCT)
#define CFG_FILE_AUDIO_HFP_PAR_TOTAL  1


typedef struct _AUDIO_SPEAKER_MONITOR_PARAM_STRUCT
{
    float resistor[512];
    float temp_initial;

    float current_sensing_resistor;

	unsigned short reso_freq_center;
    unsigned short reso_freq_bw;
    unsigned short reso_freq_gain;

    unsigned short prefer_band_upper;
    unsigned short prefer_band_lower;

    unsigned short temp_limit_low;
    unsigned short temp_limit_high;
    unsigned short temp_control_time_slots;

    unsigned short monitor_timer;
} AUDIO_SPEAKER_MONITOR_PARAM_STRUCT;


#define CFG_FILE_SPEAKER_MONITOR_SIZE   sizeof(AUDIO_SPEAKER_MONITOR_PARAM_STRUCT)
#define CFG_FILE_SPEAK_MONITOR_REC_TOTAL  1

#endif

