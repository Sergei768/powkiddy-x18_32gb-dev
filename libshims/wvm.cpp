#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include <log/log.h>
#include <media/IMediaSource.h>
#include <media/stagefright/MediaSource.h>
#include <media/stagefright/MediaBuffer.h>
#include <media/stagefright/MediaBufferGroup.h>





extern "C" {

   bool _ZNK7android12IMediaSource11ReadOptions9getSeekToEPxPNS1_8SeekModeE(void *readOptions, int64_t *time_us,
          android::IMediaSource::ReadOptions::SeekMode *mode);

   int64_t _ZNK7android12IMediaSource11ReadOptions9getLateByEv(void *readOptions);

   bool _ZNK7android11MediaSource11ReadOptions14getNonBlockingEv(android::IMediaSource::ReadOptions *readOptions) {
       ALOGW("_ZNK7android11MediaSource11ReadOptions14getNonBlockingEv");
       bool result = readOptions->getNonBlocking();
       ALOGW("_ZNK7android11MediaSource11ReadOptions14getNonBlockingEv %d", result);
       return result;
   }

   bool _ZNK7android11MediaSource11ReadOptions9getSeekToEPxPNS1_8SeekModeE(android::IMediaSource::ReadOptions *readOptions, int64_t *time_us, android::IMediaSource::ReadOptions::SeekMode *mode) {
       ALOGW("_ZNK7android11MediaSource11ReadOptions9getSeekToEPxPNS1_8SeekModeE");
       bool result = readOptions->getSeekTo(time_us, mode);
       ALOGW("_ZNK7android11MediaSource11ReadOptions9getSeekToEPxPNS1_8SeekModeE, %d, %d", *mode, result);
       return result;
   }


   android::status_t _ZN7android16MediaBufferGroup14acquire_bufferEPPNS_11MediaBufferEb(
                    android::MediaBufferGroup* group, android::MediaBuffer **out, bool nonBlocking) {
     ALOGD("_ZN7android16MediaBufferGroup14acquire_bufferEPPNS_11MediaBufferEb: %d", nonBlocking);
     return group->acquire_buffer(out, nonBlocking, 0);
   }


   int64_t _ZNK7android11MediaSource11ReadOptions9getLateByEv(android::IMediaSource::ReadOptions *readOptions) {
       ALOGW("_ZNK7android11MediaSource11ReadOptions9getLateByEv");
       int64_t result = readOptions->getLateBy();
       ALOGW("_ZNK7android11MediaSource11ReadOptions9getLateByEv %d", result);
       return result;
   }


   int _ZN7android16MediaBufferGroupC1Ej(unsigned int group) {
       ALOGI("_ZN7android16MediaBufferGroupC1Ej: %d", group);
       return group;
   }

   int _ZN7android16MediaBufferGroupC1Ev() {
       return _ZN7android16MediaBufferGroupC1Ej(0);
   }

}
