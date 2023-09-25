# automatically generated by the FlatBuffers compiler, do not modify

# namespace: AssetPack

import flatbuffers
from flatbuffers.compat import import_numpy
np = import_numpy()

class ColorRenderer(object):
    __slots__ = ['_tab']

    @classmethod
    def SizeOf(cls):
        return 24

    # ColorRenderer
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # ColorRenderer
    def Color(self, obj):
        obj.Init(self._tab.Bytes, self._tab.Pos + 0)
        return obj

    # ColorRenderer
    def Shape(self): return self._tab.Get(flatbuffers.number_types.Int32Flags, self._tab.Pos + flatbuffers.number_types.UOffsetTFlags.py_type(16))
    # ColorRenderer
    def EntityId(self): return self._tab.Get(flatbuffers.number_types.Uint32Flags, self._tab.Pos + flatbuffers.number_types.UOffsetTFlags.py_type(20))

def CreateColorRenderer(builder, color_r, color_g, color_b, color_a, shape, entityId):
    builder.Prep(4, 24)
    builder.PrependUint32(entityId)
    builder.PrependInt32(shape)
    builder.Prep(4, 16)
    builder.PrependFloat32(color_a)
    builder.PrependFloat32(color_b)
    builder.PrependFloat32(color_g)
    builder.PrependFloat32(color_r)
    return builder.Offset()