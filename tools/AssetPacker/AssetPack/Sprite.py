# automatically generated by the FlatBuffers compiler, do not modify

# namespace: AssetPack

import flatbuffers
from flatbuffers.compat import import_numpy
np = import_numpy()

class Sprite(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAs(cls, buf, offset=0):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = Sprite()
        x.Init(buf, n + offset)
        return x

    @classmethod
    def GetRootAsSprite(cls, buf, offset=0):
        """This method is deprecated. Please switch to GetRootAs."""
        return cls.GetRootAs(buf, offset)
    # Sprite
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # Sprite
    def Name(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.String(o + self._tab.Pos)
        return None

    # Sprite
    def Id(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Uint32Flags, o + self._tab.Pos)
        return 0

    # Sprite
    def Resolution(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            x = o + self._tab.Pos
            from AssetPack.vec2 import vec2
            obj = vec2()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

    # Sprite
    def ImageFileName(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            return self._tab.String(o + self._tab.Pos)
        return None

    # Sprite
    def TextureId(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(12))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

    # Sprite
    def FilterMode(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(14))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

    # Sprite
    def Atlas(self, j):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(16))
        if o != 0:
            x = self._tab.Vector(o)
            x += flatbuffers.number_types.UOffsetTFlags.py_type(j) * 4
            x = self._tab.Indirect(x)
            from AssetPack.AtlasEntry import AtlasEntry
            obj = AtlasEntry()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

    # Sprite
    def AtlasLength(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(16))
        if o != 0:
            return self._tab.VectorLen(o)
        return 0

    # Sprite
    def AtlasIsNone(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(16))
        return o == 0

    # Sprite
    def AtlasLayout(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(18))
        if o != 0:
            x = o + self._tab.Pos
            from AssetPack.AtlasLayout import AtlasLayout
            obj = AtlasLayout()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

def SpriteStart(builder):
    builder.StartObject(8)

def Start(builder):
    SpriteStart(builder)

def SpriteAddName(builder, name):
    builder.PrependUOffsetTRelativeSlot(0, flatbuffers.number_types.UOffsetTFlags.py_type(name), 0)

def AddName(builder, name):
    SpriteAddName(builder, name)

def SpriteAddId(builder, id):
    builder.PrependUint32Slot(1, id, 0)

def AddId(builder, id):
    SpriteAddId(builder, id)

def SpriteAddResolution(builder, resolution):
    builder.PrependStructSlot(2, flatbuffers.number_types.UOffsetTFlags.py_type(resolution), 0)

def AddResolution(builder, resolution):
    SpriteAddResolution(builder, resolution)

def SpriteAddImageFileName(builder, imageFileName):
    builder.PrependUOffsetTRelativeSlot(3, flatbuffers.number_types.UOffsetTFlags.py_type(imageFileName), 0)

def AddImageFileName(builder, imageFileName):
    SpriteAddImageFileName(builder, imageFileName)

def SpriteAddTextureId(builder, textureId):
    builder.PrependInt32Slot(4, textureId, 0)

def AddTextureId(builder, textureId):
    SpriteAddTextureId(builder, textureId)

def SpriteAddFilterMode(builder, filterMode):
    builder.PrependInt32Slot(5, filterMode, 0)

def AddFilterMode(builder, filterMode):
    SpriteAddFilterMode(builder, filterMode)

def SpriteAddAtlas(builder, atlas):
    builder.PrependUOffsetTRelativeSlot(6, flatbuffers.number_types.UOffsetTFlags.py_type(atlas), 0)

def AddAtlas(builder, atlas):
    SpriteAddAtlas(builder, atlas)

def SpriteStartAtlasVector(builder, numElems):
    return builder.StartVector(4, numElems, 4)

def StartAtlasVector(builder, numElems: int) -> int:
    return SpriteStartAtlasVector(builder, numElems)

def SpriteAddAtlasLayout(builder, atlasLayout):
    builder.PrependStructSlot(7, flatbuffers.number_types.UOffsetTFlags.py_type(atlasLayout), 0)

def AddAtlasLayout(builder, atlasLayout):
    SpriteAddAtlasLayout(builder, atlasLayout)

def SpriteEnd(builder):
    return builder.EndObject()

def End(builder):
    return SpriteEnd(builder)