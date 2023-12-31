// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_FONT_ASSETPACK_H_
#define FLATBUFFERS_GENERATED_FONT_ASSETPACK_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 5 &&
              FLATBUFFERS_VERSION_REVISION == 26,
             "Non-compatible flatbuffers version included");

#include "common_generated.h"

namespace AssetPack {

struct packedChar;

struct Font;
struct FontBuilder;

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(4) packedChar FLATBUFFERS_FINAL_CLASS {
 private:
  AssetPack::vec2 uvmin_;
  AssetPack::vec2 uvmax_;
  AssetPack::vec2 scale_;
  float xOff_;
  float yOff_;
  float xAdvance_;

 public:
  packedChar()
      : uvmin_(),
        uvmax_(),
        scale_(),
        xOff_(0),
        yOff_(0),
        xAdvance_(0) {
  }
  packedChar(const AssetPack::vec2 &_uvmin, const AssetPack::vec2 &_uvmax, const AssetPack::vec2 &_scale, float _xOff, float _yOff, float _xAdvance)
      : uvmin_(_uvmin),
        uvmax_(_uvmax),
        scale_(_scale),
        xOff_(::flatbuffers::EndianScalar(_xOff)),
        yOff_(::flatbuffers::EndianScalar(_yOff)),
        xAdvance_(::flatbuffers::EndianScalar(_xAdvance)) {
  }
  const AssetPack::vec2 &uvmin() const {
    return uvmin_;
  }
  const AssetPack::vec2 &uvmax() const {
    return uvmax_;
  }
  const AssetPack::vec2 &scale() const {
    return scale_;
  }
  float xOff() const {
    return ::flatbuffers::EndianScalar(xOff_);
  }
  float yOff() const {
    return ::flatbuffers::EndianScalar(yOff_);
  }
  float xAdvance() const {
    return ::flatbuffers::EndianScalar(xAdvance_);
  }
};
FLATBUFFERS_STRUCT_END(packedChar, 36);

struct Font FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef FontBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_FIRSTCHAR = 6,
    VT_CHARCOUNT = 8,
    VT_FONTHEIGHT = 10,
    VT_BASELINE = 12,
    VT_LINEGAP = 14,
    VT_ATLAS = 16,
    VT_ID = 18,
    VT_PACKEDCHARS = 20,
    VT_KERNINGTABLE = 22
  };
  const ::flatbuffers::String *name() const {
    return GetPointer<const ::flatbuffers::String *>(VT_NAME);
  }
  int32_t firstChar() const {
    return GetField<int32_t>(VT_FIRSTCHAR, 0);
  }
  int32_t charCount() const {
    return GetField<int32_t>(VT_CHARCOUNT, 0);
  }
  float fontHeight() const {
    return GetField<float>(VT_FONTHEIGHT, 0.0f);
  }
  float baseline() const {
    return GetField<float>(VT_BASELINE, 0.0f);
  }
  float lineGap() const {
    return GetField<float>(VT_LINEGAP, 0.0f);
  }
  uint32_t atlas() const {
    return GetField<uint32_t>(VT_ATLAS, 0);
  }
  uint32_t ID() const {
    return GetField<uint32_t>(VT_ID, 0);
  }
  const ::flatbuffers::Vector<const AssetPack::packedChar *> *packedChars() const {
    return GetPointer<const ::flatbuffers::Vector<const AssetPack::packedChar *> *>(VT_PACKEDCHARS);
  }
  const ::flatbuffers::Vector<float> *kerningTable() const {
    return GetPointer<const ::flatbuffers::Vector<float> *>(VT_KERNINGTABLE);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<int32_t>(verifier, VT_FIRSTCHAR, 4) &&
           VerifyField<int32_t>(verifier, VT_CHARCOUNT, 4) &&
           VerifyField<float>(verifier, VT_FONTHEIGHT, 4) &&
           VerifyField<float>(verifier, VT_BASELINE, 4) &&
           VerifyField<float>(verifier, VT_LINEGAP, 4) &&
           VerifyField<uint32_t>(verifier, VT_ATLAS, 4) &&
           VerifyField<uint32_t>(verifier, VT_ID, 4) &&
           VerifyOffset(verifier, VT_PACKEDCHARS) &&
           verifier.VerifyVector(packedChars()) &&
           VerifyOffset(verifier, VT_KERNINGTABLE) &&
           verifier.VerifyVector(kerningTable()) &&
           verifier.EndTable();
  }
};

struct FontBuilder {
  typedef Font Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_name(::flatbuffers::Offset<::flatbuffers::String> name) {
    fbb_.AddOffset(Font::VT_NAME, name);
  }
  void add_firstChar(int32_t firstChar) {
    fbb_.AddElement<int32_t>(Font::VT_FIRSTCHAR, firstChar, 0);
  }
  void add_charCount(int32_t charCount) {
    fbb_.AddElement<int32_t>(Font::VT_CHARCOUNT, charCount, 0);
  }
  void add_fontHeight(float fontHeight) {
    fbb_.AddElement<float>(Font::VT_FONTHEIGHT, fontHeight, 0.0f);
  }
  void add_baseline(float baseline) {
    fbb_.AddElement<float>(Font::VT_BASELINE, baseline, 0.0f);
  }
  void add_lineGap(float lineGap) {
    fbb_.AddElement<float>(Font::VT_LINEGAP, lineGap, 0.0f);
  }
  void add_atlas(uint32_t atlas) {
    fbb_.AddElement<uint32_t>(Font::VT_ATLAS, atlas, 0);
  }
  void add_ID(uint32_t ID) {
    fbb_.AddElement<uint32_t>(Font::VT_ID, ID, 0);
  }
  void add_packedChars(::flatbuffers::Offset<::flatbuffers::Vector<const AssetPack::packedChar *>> packedChars) {
    fbb_.AddOffset(Font::VT_PACKEDCHARS, packedChars);
  }
  void add_kerningTable(::flatbuffers::Offset<::flatbuffers::Vector<float>> kerningTable) {
    fbb_.AddOffset(Font::VT_KERNINGTABLE, kerningTable);
  }
  explicit FontBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Font> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Font>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Font> CreateFont(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::String> name = 0,
    int32_t firstChar = 0,
    int32_t charCount = 0,
    float fontHeight = 0.0f,
    float baseline = 0.0f,
    float lineGap = 0.0f,
    uint32_t atlas = 0,
    uint32_t ID = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<const AssetPack::packedChar *>> packedChars = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<float>> kerningTable = 0) {
  FontBuilder builder_(_fbb);
  builder_.add_kerningTable(kerningTable);
  builder_.add_packedChars(packedChars);
  builder_.add_ID(ID);
  builder_.add_atlas(atlas);
  builder_.add_lineGap(lineGap);
  builder_.add_baseline(baseline);
  builder_.add_fontHeight(fontHeight);
  builder_.add_charCount(charCount);
  builder_.add_firstChar(firstChar);
  builder_.add_name(name);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Font> CreateFontDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    int32_t firstChar = 0,
    int32_t charCount = 0,
    float fontHeight = 0.0f,
    float baseline = 0.0f,
    float lineGap = 0.0f,
    uint32_t atlas = 0,
    uint32_t ID = 0,
    const std::vector<AssetPack::packedChar> *packedChars = nullptr,
    const std::vector<float> *kerningTable = nullptr) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  auto packedChars__ = packedChars ? _fbb.CreateVectorOfStructs<AssetPack::packedChar>(*packedChars) : 0;
  auto kerningTable__ = kerningTable ? _fbb.CreateVector<float>(*kerningTable) : 0;
  return AssetPack::CreateFont(
      _fbb,
      name__,
      firstChar,
      charCount,
      fontHeight,
      baseline,
      lineGap,
      atlas,
      ID,
      packedChars__,
      kerningTable__);
}

inline const AssetPack::Font *GetFont(const void *buf) {
  return ::flatbuffers::GetRoot<AssetPack::Font>(buf);
}

inline const AssetPack::Font *GetSizePrefixedFont(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<AssetPack::Font>(buf);
}

inline bool VerifyFontBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<AssetPack::Font>(nullptr);
}

inline bool VerifySizePrefixedFontBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<AssetPack::Font>(nullptr);
}

inline void FinishFontBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<AssetPack::Font> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedFontBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<AssetPack::Font> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace AssetPack

#endif  // FLATBUFFERS_GENERATED_FONT_ASSETPACK_H_
