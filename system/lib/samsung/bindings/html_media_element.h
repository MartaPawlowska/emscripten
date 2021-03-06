// Copyright 2020 Samsung Electronics
// TizenTV Emscripten extensions are available under two separate licenses, the
// MIT license and the University of Illinois/NCSA Open Source License.  Both
// these licenses can be found in the LICENSE file.

#ifndef LIB_SAMSUNG_BINDINGS_HTML_MEDIA_ELEMENT_H_
#define LIB_SAMSUNG_BINDINGS_HTML_MEDIA_ELEMENT_H_

#include <stdbool.h>

#include "samsung/bindings/emss_operation_result.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*OnEventCallback)(void* userData);
typedef void (*RegisterOnTimeUpdateEMSSEventCallback)(void*, float);
typedef void (*OnErrorCallback)(int errorCode,
                                const char* errorMessage,
                                void* userData);

extern int mediaElementById(const char* id);
extern EMSSOperationResult mediaElementRemove(int handle);
extern EMSSOperationResult mediaElementIsAutoplay(int handle, bool* out);
extern EMSSOperationResult mediaElementSetAutoplay(int handle,
                                                   bool newAutoplay);
extern EMSSOperationResult mediaElementGetCurrentTime(int handle, double* out);
extern EMSSOperationResult mediaElementSetCurrentTime(int handle,
                                                      double newCurrentTime);
extern EMSSOperationResult mediaElementGetDuration(int handle, double* out);
extern EMSSOperationResult mediaElementIsEnded(int handle, bool* out);
extern EMSSOperationResult mediaElementIsLoop(int handle, bool* out);
extern EMSSOperationResult mediaElementSetLoop(int handle, bool newLoop);
extern EMSSOperationResult mediaElementIsPaused(int handle, bool* out);
extern EMSSOperationResult mediaElementGetReadyState(int handle, int* out);
extern EMSSOperationResult mediaElementGetSrc(int handle, char** out);
extern EMSSOperationResult mediaElementSetSrc(int handle, const char* newSrc);
extern EMSSOperationResult mediaElementPlay(
    int handle,
    void (*finishedCallback)(EMSSOperationResult result, void* userData),
    void* userData);
extern EMSSOperationResult mediaElementPause(int handle);

extern EMSSOperationResult mediaElementClearListeners(int handle);

extern EMSSOperationResult mediaElementSetOnPlaying(int handle,
                                                    OnEventCallback callback,
                                                    void* userData);
extern EMSSOperationResult mediaElementSetOnTimeUpdate(int handle,
                                                       OnEventCallback callback,
                                                       void* userData);
extern EMSSOperationResult mediaElementSetOnLoadStart(int handle,
                                                      OnEventCallback callback,
                                                      void* userData);
extern EMSSOperationResult mediaElementSetOnLoadedMetadata(
    int handle,
    OnEventCallback callback,
    void* userData);
extern EMSSOperationResult mediaElementSetOnLoadedData(int handle,
                                                       OnEventCallback callback,
                                                       void* userData);
extern EMSSOperationResult mediaElementSetOnCanPlay(int handle,
                                                    OnEventCallback callback,
                                                    void* userData);
extern EMSSOperationResult mediaElementSetOnCanPlayThrough(
    int handle,
    OnEventCallback callback,
    void* userData);
extern EMSSOperationResult mediaElementSetOnEnded(int handle,
                                                  OnEventCallback callback,
                                                  void* userData);
extern EMSSOperationResult mediaElementSetOnPlay(int handle,
                                                 OnEventCallback callback,
                                                 void* userData);
extern EMSSOperationResult mediaElementSetOnSeeking(int handle,
                                                    OnEventCallback callback,
                                                    void* userData);
extern EMSSOperationResult mediaElementSetOnSeeked(int handle,
                                                   OnEventCallback callback,
                                                   void* userData);
extern EMSSOperationResult mediaElementSetOnPause(int handle,
                                                  OnEventCallback callback,
                                                  void* userData);
extern EMSSOperationResult mediaElementSetOnWaiting(int handle,
                                                    OnEventCallback callback,
                                                    void* userData);
extern EMSSOperationResult mediaElementSetOnError(int handle,
                                                  OnErrorCallback callback,
                                                  void* userData);

// Fallback for EMSSSetOnPlaybackPositionChanged on legacy product
extern EMSSOperationResult mediaElementRegisterOnTimeUpdateEMSS(
    int media_element_handle,
    int source_handle,
    RegisterOnTimeUpdateEMSSEventCallback callback,
    void* listener);

extern EMSSOperationResult mediaElementUnregisterOnTimeUpdateEMSS(
    int handle,
    int sourceHandle);

#ifdef __cplusplus
}
#endif

#endif  // LIB_SAMSUNG_BINDINGS_HTML_MEDIA_ELEMENT_H_
