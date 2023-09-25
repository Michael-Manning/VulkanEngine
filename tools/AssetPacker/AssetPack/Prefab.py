# automatically generated by the FlatBuffers compiler, do not modify

# namespace: AssetPack

import flatbuffers
from flatbuffers.compat import import_numpy
np = import_numpy()

class Prefab(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAs(cls, buf, offset=0):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = Prefab()
        x.Init(buf, n + offset)
        return x

    @classmethod
    def GetRootAsPrefab(cls, buf, offset=0):
        """This method is deprecated. Please switch to GetRootAs."""
        return cls.GetRootAs(buf, offset)
    # Prefab
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # Prefab
    def Name(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.String(o + self._tab.Pos)
        return None

    # Prefab
    def BehaviorHash(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Uint32Flags, o + self._tab.Pos)
        return 0

    # Prefab
    def Transform(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            x = o + self._tab.Pos
            from AssetPack.Transform import Transform
            obj = Transform()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

    # Prefab
    def ColorRenderer(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            x = o + self._tab.Pos
            from AssetPack.ColorRenderer import ColorRenderer
            obj = ColorRenderer()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

    # Prefab
    def SpriteRenderer(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(12))
        if o != 0:
            x = o + self._tab.Pos
            from AssetPack.SpriteRenderer import SpriteRenderer
            obj = SpriteRenderer()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

    # Prefab
    def TextRenderer(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(14))
        if o != 0:
            x = self._tab.Indirect(o + self._tab.Pos)
            from AssetPack.TextRenderer import TextRenderer
            obj = TextRenderer()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

    # Prefab
    def Rigidbody(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(16))
        if o != 0:
            x = o + self._tab.Pos
            from AssetPack.Rigidbody import Rigidbody
            obj = Rigidbody()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

    # Prefab
    def Staticbody(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(18))
        if o != 0:
            x = o + self._tab.Pos
            from AssetPack.Staticbody import Staticbody
            obj = Staticbody()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

def PrefabStart(builder):
    builder.StartObject(8)

def Start(builder):
    PrefabStart(builder)

def PrefabAddName(builder, name):
    builder.PrependUOffsetTRelativeSlot(0, flatbuffers.number_types.UOffsetTFlags.py_type(name), 0)

def AddName(builder, name):
    PrefabAddName(builder, name)

def PrefabAddBehaviorHash(builder, behaviorHash):
    builder.PrependUint32Slot(1, behaviorHash, 0)

def AddBehaviorHash(builder, behaviorHash):
    PrefabAddBehaviorHash(builder, behaviorHash)

def PrefabAddTransform(builder, transform):
    builder.PrependStructSlot(2, flatbuffers.number_types.UOffsetTFlags.py_type(transform), 0)

def AddTransform(builder, transform):
    PrefabAddTransform(builder, transform)

def PrefabAddColorRenderer(builder, colorRenderer):
    builder.PrependStructSlot(3, flatbuffers.number_types.UOffsetTFlags.py_type(colorRenderer), 0)

def AddColorRenderer(builder, colorRenderer):
    PrefabAddColorRenderer(builder, colorRenderer)

def PrefabAddSpriteRenderer(builder, spriteRenderer):
    builder.PrependStructSlot(4, flatbuffers.number_types.UOffsetTFlags.py_type(spriteRenderer), 0)

def AddSpriteRenderer(builder, spriteRenderer):
    PrefabAddSpriteRenderer(builder, spriteRenderer)

def PrefabAddTextRenderer(builder, textRenderer):
    builder.PrependUOffsetTRelativeSlot(5, flatbuffers.number_types.UOffsetTFlags.py_type(textRenderer), 0)

def AddTextRenderer(builder, textRenderer):
    PrefabAddTextRenderer(builder, textRenderer)

def PrefabAddRigidbody(builder, rigidbody):
    builder.PrependStructSlot(6, flatbuffers.number_types.UOffsetTFlags.py_type(rigidbody), 0)

def AddRigidbody(builder, rigidbody):
    PrefabAddRigidbody(builder, rigidbody)

def PrefabAddStaticbody(builder, staticbody):
    builder.PrependStructSlot(7, flatbuffers.number_types.UOffsetTFlags.py_type(staticbody), 0)

def AddStaticbody(builder, staticbody):
    PrefabAddStaticbody(builder, staticbody)

def PrefabEnd(builder):
    return builder.EndObject()

def End(builder):
    return PrefabEnd(builder)