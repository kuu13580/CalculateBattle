// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_DATA_DATA_H_
#define FLATBUFFERS_GENERATED_DATA_DATA_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 22 &&
              FLATBUFFERS_VERSION_MINOR == 12 &&
              FLATBUFFERS_VERSION_REVISION == 6,
             "Non-compatible flatbuffers version included");

namespace Data {

struct Monster;
struct MonsterBuilder;

struct Text;
struct TextBuilder;

struct Player;
struct PlayerBuilder;

struct Data_list;
struct Data_listBuilder;

enum Language : int16_t {
  Language_Japanese = 0,
  Language_English = 1,
  Language_Chinese = 2,
  Language_MIN = Language_Japanese,
  Language_MAX = Language_Chinese
};

inline const Language (&EnumValuesLanguage())[3] {
  static const Language values[] = {
    Language_Japanese,
    Language_English,
    Language_Chinese
  };
  return values;
}

inline const char * const *EnumNamesLanguage() {
  static const char * const names[4] = {
    "Japanese",
    "English",
    "Chinese",
    nullptr
  };
  return names;
}

inline const char *EnumNameLanguage(Language e) {
  if (flatbuffers::IsOutRange(e, Language_Japanese, Language_Chinese)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesLanguage()[index];
}

struct Monster FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef MonsterBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_HP = 6,
    VT_AP = 8,
    VT_DP = 10,
    VT_SPEED = 12,
    VT_EMOJI = 14,
    VT_NAME_ID = 16
  };
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  int32_t hp() const {
    return GetField<int32_t>(VT_HP, 0);
  }
  int32_t ap() const {
    return GetField<int32_t>(VT_AP, 0);
  }
  int32_t dp() const {
    return GetField<int32_t>(VT_DP, 0);
  }
  int32_t speed() const {
    return GetField<int32_t>(VT_SPEED, 0);
  }
  const flatbuffers::String *emoji() const {
    return GetPointer<const flatbuffers::String *>(VT_EMOJI);
  }
  const flatbuffers::String *name_id() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME_ID);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<int32_t>(verifier, VT_HP, 4) &&
           VerifyField<int32_t>(verifier, VT_AP, 4) &&
           VerifyField<int32_t>(verifier, VT_DP, 4) &&
           VerifyField<int32_t>(verifier, VT_SPEED, 4) &&
           VerifyOffset(verifier, VT_EMOJI) &&
           verifier.VerifyString(emoji()) &&
           VerifyOffset(verifier, VT_NAME_ID) &&
           verifier.VerifyString(name_id()) &&
           verifier.EndTable();
  }
};

struct MonsterBuilder {
  typedef Monster Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Monster::VT_NAME, name);
  }
  void add_hp(int32_t hp) {
    fbb_.AddElement<int32_t>(Monster::VT_HP, hp, 0);
  }
  void add_ap(int32_t ap) {
    fbb_.AddElement<int32_t>(Monster::VT_AP, ap, 0);
  }
  void add_dp(int32_t dp) {
    fbb_.AddElement<int32_t>(Monster::VT_DP, dp, 0);
  }
  void add_speed(int32_t speed) {
    fbb_.AddElement<int32_t>(Monster::VT_SPEED, speed, 0);
  }
  void add_emoji(flatbuffers::Offset<flatbuffers::String> emoji) {
    fbb_.AddOffset(Monster::VT_EMOJI, emoji);
  }
  void add_name_id(flatbuffers::Offset<flatbuffers::String> name_id) {
    fbb_.AddOffset(Monster::VT_NAME_ID, name_id);
  }
  explicit MonsterBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Monster> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Monster>(end);
    return o;
  }
};

inline flatbuffers::Offset<Monster> CreateMonster(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    int32_t hp = 0,
    int32_t ap = 0,
    int32_t dp = 0,
    int32_t speed = 0,
    flatbuffers::Offset<flatbuffers::String> emoji = 0,
    flatbuffers::Offset<flatbuffers::String> name_id = 0) {
  MonsterBuilder builder_(_fbb);
  builder_.add_name_id(name_id);
  builder_.add_emoji(emoji);
  builder_.add_speed(speed);
  builder_.add_dp(dp);
  builder_.add_ap(ap);
  builder_.add_hp(hp);
  builder_.add_name(name);
  return builder_.Finish();
}

inline flatbuffers::Offset<Monster> CreateMonsterDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    int32_t hp = 0,
    int32_t ap = 0,
    int32_t dp = 0,
    int32_t speed = 0,
    const char *emoji = nullptr,
    const char *name_id = nullptr) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  auto emoji__ = emoji ? _fbb.CreateString(emoji) : 0;
  auto name_id__ = name_id ? _fbb.CreateString(name_id) : 0;
  return Data::CreateMonster(
      _fbb,
      name__,
      hp,
      ap,
      dp,
      speed,
      emoji__,
      name_id__);
}

struct Text FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef TextBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ID = 4,
    VT_JAPANESE = 6,
    VT_ENGLISH = 8,
    VT_CHINESE = 10
  };
  const flatbuffers::String *id() const {
    return GetPointer<const flatbuffers::String *>(VT_ID);
  }
  const flatbuffers::String *japanese() const {
    return GetPointer<const flatbuffers::String *>(VT_JAPANESE);
  }
  const flatbuffers::String *english() const {
    return GetPointer<const flatbuffers::String *>(VT_ENGLISH);
  }
  const flatbuffers::String *chinese() const {
    return GetPointer<const flatbuffers::String *>(VT_CHINESE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_ID) &&
           verifier.VerifyString(id()) &&
           VerifyOffset(verifier, VT_JAPANESE) &&
           verifier.VerifyString(japanese()) &&
           VerifyOffset(verifier, VT_ENGLISH) &&
           verifier.VerifyString(english()) &&
           VerifyOffset(verifier, VT_CHINESE) &&
           verifier.VerifyString(chinese()) &&
           verifier.EndTable();
  }
};

struct TextBuilder {
  typedef Text Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(flatbuffers::Offset<flatbuffers::String> id) {
    fbb_.AddOffset(Text::VT_ID, id);
  }
  void add_japanese(flatbuffers::Offset<flatbuffers::String> japanese) {
    fbb_.AddOffset(Text::VT_JAPANESE, japanese);
  }
  void add_english(flatbuffers::Offset<flatbuffers::String> english) {
    fbb_.AddOffset(Text::VT_ENGLISH, english);
  }
  void add_chinese(flatbuffers::Offset<flatbuffers::String> chinese) {
    fbb_.AddOffset(Text::VT_CHINESE, chinese);
  }
  explicit TextBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Text> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Text>(end);
    return o;
  }
};

inline flatbuffers::Offset<Text> CreateText(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> id = 0,
    flatbuffers::Offset<flatbuffers::String> japanese = 0,
    flatbuffers::Offset<flatbuffers::String> english = 0,
    flatbuffers::Offset<flatbuffers::String> chinese = 0) {
  TextBuilder builder_(_fbb);
  builder_.add_chinese(chinese);
  builder_.add_english(english);
  builder_.add_japanese(japanese);
  builder_.add_id(id);
  return builder_.Finish();
}

inline flatbuffers::Offset<Text> CreateTextDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *id = nullptr,
    const char *japanese = nullptr,
    const char *english = nullptr,
    const char *chinese = nullptr) {
  auto id__ = id ? _fbb.CreateString(id) : 0;
  auto japanese__ = japanese ? _fbb.CreateString(japanese) : 0;
  auto english__ = english ? _fbb.CreateString(english) : 0;
  auto chinese__ = chinese ? _fbb.CreateString(chinese) : 0;
  return Data::CreateText(
      _fbb,
      id__,
      japanese__,
      english__,
      chinese__);
}

struct Player FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef PlayerBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_HP = 4,
    VT_AP = 6,
    VT_DP = 8
  };
  int32_t hp() const {
    return GetField<int32_t>(VT_HP, 0);
  }
  int32_t ap() const {
    return GetField<int32_t>(VT_AP, 0);
  }
  int32_t dp() const {
    return GetField<int32_t>(VT_DP, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_HP, 4) &&
           VerifyField<int32_t>(verifier, VT_AP, 4) &&
           VerifyField<int32_t>(verifier, VT_DP, 4) &&
           verifier.EndTable();
  }
};

struct PlayerBuilder {
  typedef Player Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_hp(int32_t hp) {
    fbb_.AddElement<int32_t>(Player::VT_HP, hp, 0);
  }
  void add_ap(int32_t ap) {
    fbb_.AddElement<int32_t>(Player::VT_AP, ap, 0);
  }
  void add_dp(int32_t dp) {
    fbb_.AddElement<int32_t>(Player::VT_DP, dp, 0);
  }
  explicit PlayerBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Player> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Player>(end);
    return o;
  }
};

inline flatbuffers::Offset<Player> CreatePlayer(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t hp = 0,
    int32_t ap = 0,
    int32_t dp = 0) {
  PlayerBuilder builder_(_fbb);
  builder_.add_dp(dp);
  builder_.add_ap(ap);
  builder_.add_hp(hp);
  return builder_.Finish();
}

struct Data_list FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef Data_listBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_MONSTERS = 4,
    VT_TEXTS = 6,
    VT_PLAYER = 8
  };
  const flatbuffers::Vector<flatbuffers::Offset<Data::Monster>> *monsters() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Data::Monster>> *>(VT_MONSTERS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<Data::Text>> *texts() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Data::Text>> *>(VT_TEXTS);
  }
  const Data::Player *player() const {
    return GetPointer<const Data::Player *>(VT_PLAYER);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_MONSTERS) &&
           verifier.VerifyVector(monsters()) &&
           verifier.VerifyVectorOfTables(monsters()) &&
           VerifyOffset(verifier, VT_TEXTS) &&
           verifier.VerifyVector(texts()) &&
           verifier.VerifyVectorOfTables(texts()) &&
           VerifyOffset(verifier, VT_PLAYER) &&
           verifier.VerifyTable(player()) &&
           verifier.EndTable();
  }
};

struct Data_listBuilder {
  typedef Data_list Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_monsters(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Data::Monster>>> monsters) {
    fbb_.AddOffset(Data_list::VT_MONSTERS, monsters);
  }
  void add_texts(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Data::Text>>> texts) {
    fbb_.AddOffset(Data_list::VT_TEXTS, texts);
  }
  void add_player(flatbuffers::Offset<Data::Player> player) {
    fbb_.AddOffset(Data_list::VT_PLAYER, player);
  }
  explicit Data_listBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Data_list> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Data_list>(end);
    return o;
  }
};

inline flatbuffers::Offset<Data_list> CreateData_list(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Data::Monster>>> monsters = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Data::Text>>> texts = 0,
    flatbuffers::Offset<Data::Player> player = 0) {
  Data_listBuilder builder_(_fbb);
  builder_.add_player(player);
  builder_.add_texts(texts);
  builder_.add_monsters(monsters);
  return builder_.Finish();
}

inline flatbuffers::Offset<Data_list> CreateData_listDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<Data::Monster>> *monsters = nullptr,
    const std::vector<flatbuffers::Offset<Data::Text>> *texts = nullptr,
    flatbuffers::Offset<Data::Player> player = 0) {
  auto monsters__ = monsters ? _fbb.CreateVector<flatbuffers::Offset<Data::Monster>>(*monsters) : 0;
  auto texts__ = texts ? _fbb.CreateVector<flatbuffers::Offset<Data::Text>>(*texts) : 0;
  return Data::CreateData_list(
      _fbb,
      monsters__,
      texts__,
      player);
}

inline const Data::Data_list *GetData_list(const void *buf) {
  return flatbuffers::GetRoot<Data::Data_list>(buf);
}

inline const Data::Data_list *GetSizePrefixedData_list(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Data::Data_list>(buf);
}

inline bool VerifyData_listBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Data::Data_list>(nullptr);
}

inline bool VerifySizePrefixedData_listBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Data::Data_list>(nullptr);
}

inline void FinishData_listBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Data::Data_list> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedData_listBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Data::Data_list> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Data

#endif  // FLATBUFFERS_GENERATED_DATA_DATA_H_
