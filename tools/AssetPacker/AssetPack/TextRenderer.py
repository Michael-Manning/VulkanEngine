# automatically generated by the FlatBuffers compiler, do not modify

# namespace: AssetPack

import flatbuffers
from flatbuffers.compat import import_numpy
np = import_numpy()

class TextRenderer(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAs(cls, buf, offset=0):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = TextRenderer()
        x.Init(buf, n + offset)
        return x

    @classmethod
    def GetRootAsTextRenderer(cls, buf, offset=0):
        """This method is deprecated. Please switch to GetRootAs."""
        return cls.GetRootAs(buf, offset)
    # TextRenderer
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # TextRenderer
    def Text(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.String(o + self._tab.Pos)
        return None

    # TextRenderer
    def FontId(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Uint32Flags, o + self._tab.Pos)
        return 0

    # TextRenderer
    def EntityId(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Uint32Flags, o + self._tab.Pos)
        return 0

    # TextRenderer
    def Color(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            x = o + self._tab.Pos
            from AssetPack.vec4 import vec4
            obj = vec4()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

def TextRendererStart(builder):
    builder.StartObject(4)

def Start(builder):
    TextRendererStart(builder)

def TextRendererAddText(builder, text):
    builder.PrependUOffsetTRelativeSlot(0, flatbuffers.number_types.UOffsetTFlags.py_type(text), 0)

def AddText(builder, text):
    TextRendererAddText(builder, text)

def TextRendererAddFontId(builder, fontId):
    builder.PrependUint32Slot(1, fontId, 0)

def AddFontId(builder, fontId):
    TextRendererAddFontId(builder, fontId)

def TextRendererAddEntityId(builder, entityId):
    builder.PrependUint32Slot(2, entityId, 0)

def AddEntityId(builder, entityId):
    TextRendererAddEntityId(builder, entityId)

def TextRendererAddColor(builder, color):
    builder.PrependStructSlot(3, flatbuffers.number_types.UOffsetTFlags.py_type(color), 0)

def AddColor(builder, color):
    TextRendererAddColor(builder, color)

def TextRendererEnd(builder):
    return builder.EndObject()

def End(builder):
    return TextRendererEnd(builder)
