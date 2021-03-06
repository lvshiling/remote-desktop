// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: desktop_session.proto

#ifndef PROTOBUF_desktop_5fsession_2eproto__INCLUDED
#define PROTOBUF_desktop_5fsession_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include "desktop_session_message.pb.h"
// @@protoc_insertion_point(includes)
namespace aspia {
namespace proto {
namespace desktop {
class ClientToHost;
class ClientToHostDefaultTypeInternal;
extern ClientToHostDefaultTypeInternal _ClientToHost_default_instance_;
class HostToClient;
class HostToClientDefaultTypeInternal;
extern HostToClientDefaultTypeInternal _HostToClient_default_instance_;
}  // namespace desktop
}  // namespace proto
}  // namespace aspia

namespace aspia {
namespace proto {
namespace desktop {

namespace protobuf_desktop_5fsession_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_desktop_5fsession_2eproto

// ===================================================================

class HostToClient : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:aspia.proto.desktop.HostToClient) */ {
 public:
  HostToClient();
  virtual ~HostToClient();

  HostToClient(const HostToClient& from);

  inline HostToClient& operator=(const HostToClient& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  HostToClient(HostToClient&& from) noexcept
    : HostToClient() {
    *this = ::std::move(from);
  }

  inline HostToClient& operator=(HostToClient&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const HostToClient& default_instance();

  static inline const HostToClient* internal_default_instance() {
    return reinterpret_cast<const HostToClient*>(
               &_HostToClient_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(HostToClient* other);
  friend void swap(HostToClient& a, HostToClient& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline HostToClient* New() const PROTOBUF_FINAL { return New(NULL); }

  HostToClient* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const HostToClient& from);
  void MergeFrom(const HostToClient& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(HostToClient* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .aspia.proto.VideoPacket video_packet = 1;
  bool has_video_packet() const;
  void clear_video_packet();
  static const int kVideoPacketFieldNumber = 1;
  const ::aspia::proto::VideoPacket& video_packet() const;
  ::aspia::proto::VideoPacket* mutable_video_packet();
  ::aspia::proto::VideoPacket* release_video_packet();
  void set_allocated_video_packet(::aspia::proto::VideoPacket* video_packet);

  // .aspia.proto.AudioPacket audio_packet = 2;
  bool has_audio_packet() const;
  void clear_audio_packet();
  static const int kAudioPacketFieldNumber = 2;
  const ::aspia::proto::AudioPacket& audio_packet() const;
  ::aspia::proto::AudioPacket* mutable_audio_packet();
  ::aspia::proto::AudioPacket* release_audio_packet();
  void set_allocated_audio_packet(::aspia::proto::AudioPacket* audio_packet);

  // .aspia.proto.CursorShape cursor_shape = 3;
  bool has_cursor_shape() const;
  void clear_cursor_shape();
  static const int kCursorShapeFieldNumber = 3;
  const ::aspia::proto::CursorShape& cursor_shape() const;
  ::aspia::proto::CursorShape* mutable_cursor_shape();
  ::aspia::proto::CursorShape* release_cursor_shape();
  void set_allocated_cursor_shape(::aspia::proto::CursorShape* cursor_shape);

  // .aspia.proto.ClipboardEvent clipboard_event = 4;
  bool has_clipboard_event() const;
  void clear_clipboard_event();
  static const int kClipboardEventFieldNumber = 4;
  const ::aspia::proto::ClipboardEvent& clipboard_event() const;
  ::aspia::proto::ClipboardEvent* mutable_clipboard_event();
  ::aspia::proto::ClipboardEvent* release_clipboard_event();
  void set_allocated_clipboard_event(::aspia::proto::ClipboardEvent* clipboard_event);

  // .aspia.proto.DesktopSessionConfigRequest config_request = 5;
  bool has_config_request() const;
  void clear_config_request();
  static const int kConfigRequestFieldNumber = 5;
  const ::aspia::proto::DesktopSessionConfigRequest& config_request() const;
  ::aspia::proto::DesktopSessionConfigRequest* mutable_config_request();
  ::aspia::proto::DesktopSessionConfigRequest* release_config_request();
  void set_allocated_config_request(::aspia::proto::DesktopSessionConfigRequest* config_request);

  // @@protoc_insertion_point(class_scope:aspia.proto.desktop.HostToClient)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::aspia::proto::VideoPacket* video_packet_;
  ::aspia::proto::AudioPacket* audio_packet_;
  ::aspia::proto::CursorShape* cursor_shape_;
  ::aspia::proto::ClipboardEvent* clipboard_event_;
  ::aspia::proto::DesktopSessionConfigRequest* config_request_;
  mutable int _cached_size_;
  friend struct protobuf_desktop_5fsession_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class ClientToHost : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:aspia.proto.desktop.ClientToHost) */ {
 public:
  ClientToHost();
  virtual ~ClientToHost();

  ClientToHost(const ClientToHost& from);

  inline ClientToHost& operator=(const ClientToHost& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ClientToHost(ClientToHost&& from) noexcept
    : ClientToHost() {
    *this = ::std::move(from);
  }

  inline ClientToHost& operator=(ClientToHost&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ClientToHost& default_instance();

  static inline const ClientToHost* internal_default_instance() {
    return reinterpret_cast<const ClientToHost*>(
               &_ClientToHost_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(ClientToHost* other);
  friend void swap(ClientToHost& a, ClientToHost& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ClientToHost* New() const PROTOBUF_FINAL { return New(NULL); }

  ClientToHost* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const ClientToHost& from);
  void MergeFrom(const ClientToHost& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ClientToHost* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .aspia.proto.PointerEvent pointer_event = 1;
  bool has_pointer_event() const;
  void clear_pointer_event();
  static const int kPointerEventFieldNumber = 1;
  const ::aspia::proto::PointerEvent& pointer_event() const;
  ::aspia::proto::PointerEvent* mutable_pointer_event();
  ::aspia::proto::PointerEvent* release_pointer_event();
  void set_allocated_pointer_event(::aspia::proto::PointerEvent* pointer_event);

  // .aspia.proto.KeyEvent key_event = 2;
  bool has_key_event() const;
  void clear_key_event();
  static const int kKeyEventFieldNumber = 2;
  const ::aspia::proto::KeyEvent& key_event() const;
  ::aspia::proto::KeyEvent* mutable_key_event();
  ::aspia::proto::KeyEvent* release_key_event();
  void set_allocated_key_event(::aspia::proto::KeyEvent* key_event);

  // .aspia.proto.ClipboardEvent clipboard_event = 3;
  bool has_clipboard_event() const;
  void clear_clipboard_event();
  static const int kClipboardEventFieldNumber = 3;
  const ::aspia::proto::ClipboardEvent& clipboard_event() const;
  ::aspia::proto::ClipboardEvent* mutable_clipboard_event();
  ::aspia::proto::ClipboardEvent* release_clipboard_event();
  void set_allocated_clipboard_event(::aspia::proto::ClipboardEvent* clipboard_event);

  // .aspia.proto.DesktopSessionConfig config = 4;
  bool has_config() const;
  void clear_config();
  static const int kConfigFieldNumber = 4;
  const ::aspia::proto::DesktopSessionConfig& config() const;
  ::aspia::proto::DesktopSessionConfig* mutable_config();
  ::aspia::proto::DesktopSessionConfig* release_config();
  void set_allocated_config(::aspia::proto::DesktopSessionConfig* config);

  // @@protoc_insertion_point(class_scope:aspia.proto.desktop.ClientToHost)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::aspia::proto::PointerEvent* pointer_event_;
  ::aspia::proto::KeyEvent* key_event_;
  ::aspia::proto::ClipboardEvent* clipboard_event_;
  ::aspia::proto::DesktopSessionConfig* config_;
  mutable int _cached_size_;
  friend struct protobuf_desktop_5fsession_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// HostToClient

// .aspia.proto.VideoPacket video_packet = 1;
inline bool HostToClient::has_video_packet() const {
  return this != internal_default_instance() && video_packet_ != NULL;
}
inline void HostToClient::clear_video_packet() {
  if (GetArenaNoVirtual() == NULL && video_packet_ != NULL) delete video_packet_;
  video_packet_ = NULL;
}
inline const ::aspia::proto::VideoPacket& HostToClient::video_packet() const {
  const ::aspia::proto::VideoPacket* p = video_packet_;
  // @@protoc_insertion_point(field_get:aspia.proto.desktop.HostToClient.video_packet)
  return p != NULL ? *p : *reinterpret_cast<const ::aspia::proto::VideoPacket*>(
      &::aspia::proto::_VideoPacket_default_instance_);
}
inline ::aspia::proto::VideoPacket* HostToClient::mutable_video_packet() {
  
  if (video_packet_ == NULL) {
    video_packet_ = new ::aspia::proto::VideoPacket;
  }
  // @@protoc_insertion_point(field_mutable:aspia.proto.desktop.HostToClient.video_packet)
  return video_packet_;
}
inline ::aspia::proto::VideoPacket* HostToClient::release_video_packet() {
  // @@protoc_insertion_point(field_release:aspia.proto.desktop.HostToClient.video_packet)
  
  ::aspia::proto::VideoPacket* temp = video_packet_;
  video_packet_ = NULL;
  return temp;
}
inline void HostToClient::set_allocated_video_packet(::aspia::proto::VideoPacket* video_packet) {
  delete video_packet_;
  video_packet_ = video_packet;
  if (video_packet) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:aspia.proto.desktop.HostToClient.video_packet)
}

// .aspia.proto.AudioPacket audio_packet = 2;
inline bool HostToClient::has_audio_packet() const {
  return this != internal_default_instance() && audio_packet_ != NULL;
}
inline void HostToClient::clear_audio_packet() {
  if (GetArenaNoVirtual() == NULL && audio_packet_ != NULL) delete audio_packet_;
  audio_packet_ = NULL;
}
inline const ::aspia::proto::AudioPacket& HostToClient::audio_packet() const {
  const ::aspia::proto::AudioPacket* p = audio_packet_;
  // @@protoc_insertion_point(field_get:aspia.proto.desktop.HostToClient.audio_packet)
  return p != NULL ? *p : *reinterpret_cast<const ::aspia::proto::AudioPacket*>(
      &::aspia::proto::_AudioPacket_default_instance_);
}
inline ::aspia::proto::AudioPacket* HostToClient::mutable_audio_packet() {
  
  if (audio_packet_ == NULL) {
    audio_packet_ = new ::aspia::proto::AudioPacket;
  }
  // @@protoc_insertion_point(field_mutable:aspia.proto.desktop.HostToClient.audio_packet)
  return audio_packet_;
}
inline ::aspia::proto::AudioPacket* HostToClient::release_audio_packet() {
  // @@protoc_insertion_point(field_release:aspia.proto.desktop.HostToClient.audio_packet)
  
  ::aspia::proto::AudioPacket* temp = audio_packet_;
  audio_packet_ = NULL;
  return temp;
}
inline void HostToClient::set_allocated_audio_packet(::aspia::proto::AudioPacket* audio_packet) {
  delete audio_packet_;
  audio_packet_ = audio_packet;
  if (audio_packet) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:aspia.proto.desktop.HostToClient.audio_packet)
}

// .aspia.proto.CursorShape cursor_shape = 3;
inline bool HostToClient::has_cursor_shape() const {
  return this != internal_default_instance() && cursor_shape_ != NULL;
}
inline void HostToClient::clear_cursor_shape() {
  if (GetArenaNoVirtual() == NULL && cursor_shape_ != NULL) delete cursor_shape_;
  cursor_shape_ = NULL;
}
inline const ::aspia::proto::CursorShape& HostToClient::cursor_shape() const {
  const ::aspia::proto::CursorShape* p = cursor_shape_;
  // @@protoc_insertion_point(field_get:aspia.proto.desktop.HostToClient.cursor_shape)
  return p != NULL ? *p : *reinterpret_cast<const ::aspia::proto::CursorShape*>(
      &::aspia::proto::_CursorShape_default_instance_);
}
inline ::aspia::proto::CursorShape* HostToClient::mutable_cursor_shape() {
  
  if (cursor_shape_ == NULL) {
    cursor_shape_ = new ::aspia::proto::CursorShape;
  }
  // @@protoc_insertion_point(field_mutable:aspia.proto.desktop.HostToClient.cursor_shape)
  return cursor_shape_;
}
inline ::aspia::proto::CursorShape* HostToClient::release_cursor_shape() {
  // @@protoc_insertion_point(field_release:aspia.proto.desktop.HostToClient.cursor_shape)
  
  ::aspia::proto::CursorShape* temp = cursor_shape_;
  cursor_shape_ = NULL;
  return temp;
}
inline void HostToClient::set_allocated_cursor_shape(::aspia::proto::CursorShape* cursor_shape) {
  delete cursor_shape_;
  cursor_shape_ = cursor_shape;
  if (cursor_shape) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:aspia.proto.desktop.HostToClient.cursor_shape)
}

// .aspia.proto.ClipboardEvent clipboard_event = 4;
inline bool HostToClient::has_clipboard_event() const {
  return this != internal_default_instance() && clipboard_event_ != NULL;
}
inline void HostToClient::clear_clipboard_event() {
  if (GetArenaNoVirtual() == NULL && clipboard_event_ != NULL) delete clipboard_event_;
  clipboard_event_ = NULL;
}
inline const ::aspia::proto::ClipboardEvent& HostToClient::clipboard_event() const {
  const ::aspia::proto::ClipboardEvent* p = clipboard_event_;
  // @@protoc_insertion_point(field_get:aspia.proto.desktop.HostToClient.clipboard_event)
  return p != NULL ? *p : *reinterpret_cast<const ::aspia::proto::ClipboardEvent*>(
      &::aspia::proto::_ClipboardEvent_default_instance_);
}
inline ::aspia::proto::ClipboardEvent* HostToClient::mutable_clipboard_event() {
  
  if (clipboard_event_ == NULL) {
    clipboard_event_ = new ::aspia::proto::ClipboardEvent;
  }
  // @@protoc_insertion_point(field_mutable:aspia.proto.desktop.HostToClient.clipboard_event)
  return clipboard_event_;
}
inline ::aspia::proto::ClipboardEvent* HostToClient::release_clipboard_event() {
  // @@protoc_insertion_point(field_release:aspia.proto.desktop.HostToClient.clipboard_event)
  
  ::aspia::proto::ClipboardEvent* temp = clipboard_event_;
  clipboard_event_ = NULL;
  return temp;
}
inline void HostToClient::set_allocated_clipboard_event(::aspia::proto::ClipboardEvent* clipboard_event) {
  delete clipboard_event_;
  clipboard_event_ = clipboard_event;
  if (clipboard_event) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:aspia.proto.desktop.HostToClient.clipboard_event)
}

// .aspia.proto.DesktopSessionConfigRequest config_request = 5;
inline bool HostToClient::has_config_request() const {
  return this != internal_default_instance() && config_request_ != NULL;
}
inline void HostToClient::clear_config_request() {
  if (GetArenaNoVirtual() == NULL && config_request_ != NULL) delete config_request_;
  config_request_ = NULL;
}
inline const ::aspia::proto::DesktopSessionConfigRequest& HostToClient::config_request() const {
  const ::aspia::proto::DesktopSessionConfigRequest* p = config_request_;
  // @@protoc_insertion_point(field_get:aspia.proto.desktop.HostToClient.config_request)
  return p != NULL ? *p : *reinterpret_cast<const ::aspia::proto::DesktopSessionConfigRequest*>(
      &::aspia::proto::_DesktopSessionConfigRequest_default_instance_);
}
inline ::aspia::proto::DesktopSessionConfigRequest* HostToClient::mutable_config_request() {
  
  if (config_request_ == NULL) {
    config_request_ = new ::aspia::proto::DesktopSessionConfigRequest;
  }
  // @@protoc_insertion_point(field_mutable:aspia.proto.desktop.HostToClient.config_request)
  return config_request_;
}
inline ::aspia::proto::DesktopSessionConfigRequest* HostToClient::release_config_request() {
  // @@protoc_insertion_point(field_release:aspia.proto.desktop.HostToClient.config_request)
  
  ::aspia::proto::DesktopSessionConfigRequest* temp = config_request_;
  config_request_ = NULL;
  return temp;
}
inline void HostToClient::set_allocated_config_request(::aspia::proto::DesktopSessionConfigRequest* config_request) {
  delete config_request_;
  config_request_ = config_request;
  if (config_request) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:aspia.proto.desktop.HostToClient.config_request)
}

// -------------------------------------------------------------------

// ClientToHost

// .aspia.proto.PointerEvent pointer_event = 1;
inline bool ClientToHost::has_pointer_event() const {
  return this != internal_default_instance() && pointer_event_ != NULL;
}
inline void ClientToHost::clear_pointer_event() {
  if (GetArenaNoVirtual() == NULL && pointer_event_ != NULL) delete pointer_event_;
  pointer_event_ = NULL;
}
inline const ::aspia::proto::PointerEvent& ClientToHost::pointer_event() const {
  const ::aspia::proto::PointerEvent* p = pointer_event_;
  // @@protoc_insertion_point(field_get:aspia.proto.desktop.ClientToHost.pointer_event)
  return p != NULL ? *p : *reinterpret_cast<const ::aspia::proto::PointerEvent*>(
      &::aspia::proto::_PointerEvent_default_instance_);
}
inline ::aspia::proto::PointerEvent* ClientToHost::mutable_pointer_event() {
  
  if (pointer_event_ == NULL) {
    pointer_event_ = new ::aspia::proto::PointerEvent;
  }
  // @@protoc_insertion_point(field_mutable:aspia.proto.desktop.ClientToHost.pointer_event)
  return pointer_event_;
}
inline ::aspia::proto::PointerEvent* ClientToHost::release_pointer_event() {
  // @@protoc_insertion_point(field_release:aspia.proto.desktop.ClientToHost.pointer_event)
  
  ::aspia::proto::PointerEvent* temp = pointer_event_;
  pointer_event_ = NULL;
  return temp;
}
inline void ClientToHost::set_allocated_pointer_event(::aspia::proto::PointerEvent* pointer_event) {
  delete pointer_event_;
  pointer_event_ = pointer_event;
  if (pointer_event) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:aspia.proto.desktop.ClientToHost.pointer_event)
}

// .aspia.proto.KeyEvent key_event = 2;
inline bool ClientToHost::has_key_event() const {
  return this != internal_default_instance() && key_event_ != NULL;
}
inline void ClientToHost::clear_key_event() {
  if (GetArenaNoVirtual() == NULL && key_event_ != NULL) delete key_event_;
  key_event_ = NULL;
}
inline const ::aspia::proto::KeyEvent& ClientToHost::key_event() const {
  const ::aspia::proto::KeyEvent* p = key_event_;
  // @@protoc_insertion_point(field_get:aspia.proto.desktop.ClientToHost.key_event)
  return p != NULL ? *p : *reinterpret_cast<const ::aspia::proto::KeyEvent*>(
      &::aspia::proto::_KeyEvent_default_instance_);
}
inline ::aspia::proto::KeyEvent* ClientToHost::mutable_key_event() {
  
  if (key_event_ == NULL) {
    key_event_ = new ::aspia::proto::KeyEvent;
  }
  // @@protoc_insertion_point(field_mutable:aspia.proto.desktop.ClientToHost.key_event)
  return key_event_;
}
inline ::aspia::proto::KeyEvent* ClientToHost::release_key_event() {
  // @@protoc_insertion_point(field_release:aspia.proto.desktop.ClientToHost.key_event)
  
  ::aspia::proto::KeyEvent* temp = key_event_;
  key_event_ = NULL;
  return temp;
}
inline void ClientToHost::set_allocated_key_event(::aspia::proto::KeyEvent* key_event) {
  delete key_event_;
  key_event_ = key_event;
  if (key_event) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:aspia.proto.desktop.ClientToHost.key_event)
}

// .aspia.proto.ClipboardEvent clipboard_event = 3;
inline bool ClientToHost::has_clipboard_event() const {
  return this != internal_default_instance() && clipboard_event_ != NULL;
}
inline void ClientToHost::clear_clipboard_event() {
  if (GetArenaNoVirtual() == NULL && clipboard_event_ != NULL) delete clipboard_event_;
  clipboard_event_ = NULL;
}
inline const ::aspia::proto::ClipboardEvent& ClientToHost::clipboard_event() const {
  const ::aspia::proto::ClipboardEvent* p = clipboard_event_;
  // @@protoc_insertion_point(field_get:aspia.proto.desktop.ClientToHost.clipboard_event)
  return p != NULL ? *p : *reinterpret_cast<const ::aspia::proto::ClipboardEvent*>(
      &::aspia::proto::_ClipboardEvent_default_instance_);
}
inline ::aspia::proto::ClipboardEvent* ClientToHost::mutable_clipboard_event() {
  
  if (clipboard_event_ == NULL) {
    clipboard_event_ = new ::aspia::proto::ClipboardEvent;
  }
  // @@protoc_insertion_point(field_mutable:aspia.proto.desktop.ClientToHost.clipboard_event)
  return clipboard_event_;
}
inline ::aspia::proto::ClipboardEvent* ClientToHost::release_clipboard_event() {
  // @@protoc_insertion_point(field_release:aspia.proto.desktop.ClientToHost.clipboard_event)
  
  ::aspia::proto::ClipboardEvent* temp = clipboard_event_;
  clipboard_event_ = NULL;
  return temp;
}
inline void ClientToHost::set_allocated_clipboard_event(::aspia::proto::ClipboardEvent* clipboard_event) {
  delete clipboard_event_;
  clipboard_event_ = clipboard_event;
  if (clipboard_event) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:aspia.proto.desktop.ClientToHost.clipboard_event)
}

// .aspia.proto.DesktopSessionConfig config = 4;
inline bool ClientToHost::has_config() const {
  return this != internal_default_instance() && config_ != NULL;
}
inline void ClientToHost::clear_config() {
  if (GetArenaNoVirtual() == NULL && config_ != NULL) delete config_;
  config_ = NULL;
}
inline const ::aspia::proto::DesktopSessionConfig& ClientToHost::config() const {
  const ::aspia::proto::DesktopSessionConfig* p = config_;
  // @@protoc_insertion_point(field_get:aspia.proto.desktop.ClientToHost.config)
  return p != NULL ? *p : *reinterpret_cast<const ::aspia::proto::DesktopSessionConfig*>(
      &::aspia::proto::_DesktopSessionConfig_default_instance_);
}
inline ::aspia::proto::DesktopSessionConfig* ClientToHost::mutable_config() {
  
  if (config_ == NULL) {
    config_ = new ::aspia::proto::DesktopSessionConfig;
  }
  // @@protoc_insertion_point(field_mutable:aspia.proto.desktop.ClientToHost.config)
  return config_;
}
inline ::aspia::proto::DesktopSessionConfig* ClientToHost::release_config() {
  // @@protoc_insertion_point(field_release:aspia.proto.desktop.ClientToHost.config)
  
  ::aspia::proto::DesktopSessionConfig* temp = config_;
  config_ = NULL;
  return temp;
}
inline void ClientToHost::set_allocated_config(::aspia::proto::DesktopSessionConfig* config) {
  delete config_;
  config_ = config;
  if (config) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:aspia.proto.desktop.ClientToHost.config)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace desktop
}  // namespace proto
}  // namespace aspia

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_desktop_5fsession_2eproto__INCLUDED
