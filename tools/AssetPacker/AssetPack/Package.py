# automatically generated by the FlatBuffers compiler, do not modify

# namespace: AssetPack

import flatbuffers
from flatbuffers.compat import import_numpy
np = import_numpy()

class Package(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAs(cls, buf, offset=0):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = Package()
        x.Init(buf, n + offset)
        return x

    @classmethod
    def GetRootAsPackage(cls, buf, offset=0):
        """This method is deprecated. Please switch to GetRootAs."""
        return cls.GetRootAs(buf, offset)
    # Package
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # Package
    def SpriteNames(self, j):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            a = self._tab.Vector(o)
            return self._tab.String(a + flatbuffers.number_types.UOffsetTFlags.py_type(j * 4))
        return ""

    # Package
    def SpriteNamesLength(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.VectorLen(o)
        return 0

    # Package
    def SpriteNamesIsNone(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        return o == 0

    # Package
    def SpriteIds(self, j):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            a = self._tab.Vector(o)
            return self._tab.Get(flatbuffers.number_types.Uint32Flags, a + flatbuffers.number_types.UOffsetTFlags.py_type(j * 4))
        return 0

    # Package
    def SpriteIdsAsNumpy(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.GetVectorAsNumpy(flatbuffers.number_types.Uint32Flags, o)
        return 0

    # Package
    def SpriteIdsLength(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.VectorLen(o)
        return 0

    # Package
    def SpriteIdsIsNone(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        return o == 0

    # Package
    def FontNames(self, j):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            a = self._tab.Vector(o)
            return self._tab.String(a + flatbuffers.number_types.UOffsetTFlags.py_type(j * 4))
        return ""

    # Package
    def FontNamesLength(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            return self._tab.VectorLen(o)
        return 0

    # Package
    def FontNamesIsNone(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        return o == 0

    # Package
    def FontIds(self, j):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            a = self._tab.Vector(o)
            return self._tab.Get(flatbuffers.number_types.Uint32Flags, a + flatbuffers.number_types.UOffsetTFlags.py_type(j * 4))
        return 0

    # Package
    def FontIdsAsNumpy(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            return self._tab.GetVectorAsNumpy(flatbuffers.number_types.Uint32Flags, o)
        return 0

    # Package
    def FontIdsLength(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            return self._tab.VectorLen(o)
        return 0

    # Package
    def FontIdsIsNone(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        return o == 0

    # Package
    def PrefabNames(self, j):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(12))
        if o != 0:
            a = self._tab.Vector(o)
            return self._tab.String(a + flatbuffers.number_types.UOffsetTFlags.py_type(j * 4))
        return ""

    # Package
    def PrefabNamesLength(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(12))
        if o != 0:
            return self._tab.VectorLen(o)
        return 0

    # Package
    def PrefabNamesIsNone(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(12))
        return o == 0

    # Package
    def SceneNames(self, j):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(14))
        if o != 0:
            a = self._tab.Vector(o)
            return self._tab.String(a + flatbuffers.number_types.UOffsetTFlags.py_type(j * 4))
        return ""

    # Package
    def SceneNamesLength(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(14))
        if o != 0:
            return self._tab.VectorLen(o)
        return 0

    # Package
    def SceneNamesIsNone(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(14))
        return o == 0

    # Package
    def Sprites(self, j):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(16))
        if o != 0:
            x = self._tab.Vector(o)
            x += flatbuffers.number_types.UOffsetTFlags.py_type(j) * 4
            x = self._tab.Indirect(x)
            from AssetPack.Sprite import Sprite
            obj = Sprite()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

    # Package
    def SpritesLength(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(16))
        if o != 0:
            return self._tab.VectorLen(o)
        return 0

    # Package
    def SpritesIsNone(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(16))
        return o == 0

    # Package
    def Fonts(self, j):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(18))
        if o != 0:
            x = self._tab.Vector(o)
            x += flatbuffers.number_types.UOffsetTFlags.py_type(j) * 4
            x = self._tab.Indirect(x)
            from AssetPack.Font import Font
            obj = Font()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

    # Package
    def FontsLength(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(18))
        if o != 0:
            return self._tab.VectorLen(o)
        return 0

    # Package
    def FontsIsNone(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(18))
        return o == 0

    # Package
    def Prefabs(self, j):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(20))
        if o != 0:
            x = self._tab.Vector(o)
            x += flatbuffers.number_types.UOffsetTFlags.py_type(j) * 4
            x = self._tab.Indirect(x)
            from AssetPack.Prefab import Prefab
            obj = Prefab()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

    # Package
    def PrefabsLength(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(20))
        if o != 0:
            return self._tab.VectorLen(o)
        return 0

    # Package
    def PrefabsIsNone(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(20))
        return o == 0

    # Package
    def Scenes(self, j):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(22))
        if o != 0:
            x = self._tab.Vector(o)
            x += flatbuffers.number_types.UOffsetTFlags.py_type(j) * 4
            x = self._tab.Indirect(x)
            from AssetPack.Scene import Scene
            obj = Scene()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

    # Package
    def ScenesLength(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(22))
        if o != 0:
            return self._tab.VectorLen(o)
        return 0

    # Package
    def ScenesIsNone(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(22))
        return o == 0

def PackageStart(builder):
    builder.StartObject(10)

def Start(builder):
    PackageStart(builder)

def PackageAddSpriteNames(builder, spriteNames):
    builder.PrependUOffsetTRelativeSlot(0, flatbuffers.number_types.UOffsetTFlags.py_type(spriteNames), 0)

def AddSpriteNames(builder, spriteNames):
    PackageAddSpriteNames(builder, spriteNames)

def PackageStartSpriteNamesVector(builder, numElems):
    return builder.StartVector(4, numElems, 4)

def StartSpriteNamesVector(builder, numElems: int) -> int:
    return PackageStartSpriteNamesVector(builder, numElems)

def PackageAddSpriteIds(builder, spriteIds):
    builder.PrependUOffsetTRelativeSlot(1, flatbuffers.number_types.UOffsetTFlags.py_type(spriteIds), 0)

def AddSpriteIds(builder, spriteIds):
    PackageAddSpriteIds(builder, spriteIds)

def PackageStartSpriteIdsVector(builder, numElems):
    return builder.StartVector(4, numElems, 4)

def StartSpriteIdsVector(builder, numElems: int) -> int:
    return PackageStartSpriteIdsVector(builder, numElems)

def PackageAddFontNames(builder, fontNames):
    builder.PrependUOffsetTRelativeSlot(2, flatbuffers.number_types.UOffsetTFlags.py_type(fontNames), 0)

def AddFontNames(builder, fontNames):
    PackageAddFontNames(builder, fontNames)

def PackageStartFontNamesVector(builder, numElems):
    return builder.StartVector(4, numElems, 4)

def StartFontNamesVector(builder, numElems: int) -> int:
    return PackageStartFontNamesVector(builder, numElems)

def PackageAddFontIds(builder, fontIds):
    builder.PrependUOffsetTRelativeSlot(3, flatbuffers.number_types.UOffsetTFlags.py_type(fontIds), 0)

def AddFontIds(builder, fontIds):
    PackageAddFontIds(builder, fontIds)

def PackageStartFontIdsVector(builder, numElems):
    return builder.StartVector(4, numElems, 4)

def StartFontIdsVector(builder, numElems: int) -> int:
    return PackageStartFontIdsVector(builder, numElems)

def PackageAddPrefabNames(builder, prefabNames):
    builder.PrependUOffsetTRelativeSlot(4, flatbuffers.number_types.UOffsetTFlags.py_type(prefabNames), 0)

def AddPrefabNames(builder, prefabNames):
    PackageAddPrefabNames(builder, prefabNames)

def PackageStartPrefabNamesVector(builder, numElems):
    return builder.StartVector(4, numElems, 4)

def StartPrefabNamesVector(builder, numElems: int) -> int:
    return PackageStartPrefabNamesVector(builder, numElems)

def PackageAddSceneNames(builder, sceneNames):
    builder.PrependUOffsetTRelativeSlot(5, flatbuffers.number_types.UOffsetTFlags.py_type(sceneNames), 0)

def AddSceneNames(builder, sceneNames):
    PackageAddSceneNames(builder, sceneNames)

def PackageStartSceneNamesVector(builder, numElems):
    return builder.StartVector(4, numElems, 4)

def StartSceneNamesVector(builder, numElems: int) -> int:
    return PackageStartSceneNamesVector(builder, numElems)

def PackageAddSprites(builder, sprites):
    builder.PrependUOffsetTRelativeSlot(6, flatbuffers.number_types.UOffsetTFlags.py_type(sprites), 0)

def AddSprites(builder, sprites):
    PackageAddSprites(builder, sprites)

def PackageStartSpritesVector(builder, numElems):
    return builder.StartVector(4, numElems, 4)

def StartSpritesVector(builder, numElems: int) -> int:
    return PackageStartSpritesVector(builder, numElems)

def PackageAddFonts(builder, fonts):
    builder.PrependUOffsetTRelativeSlot(7, flatbuffers.number_types.UOffsetTFlags.py_type(fonts), 0)

def AddFonts(builder, fonts):
    PackageAddFonts(builder, fonts)

def PackageStartFontsVector(builder, numElems):
    return builder.StartVector(4, numElems, 4)

def StartFontsVector(builder, numElems: int) -> int:
    return PackageStartFontsVector(builder, numElems)

def PackageAddPrefabs(builder, prefabs):
    builder.PrependUOffsetTRelativeSlot(8, flatbuffers.number_types.UOffsetTFlags.py_type(prefabs), 0)

def AddPrefabs(builder, prefabs):
    PackageAddPrefabs(builder, prefabs)

def PackageStartPrefabsVector(builder, numElems):
    return builder.StartVector(4, numElems, 4)

def StartPrefabsVector(builder, numElems: int) -> int:
    return PackageStartPrefabsVector(builder, numElems)

def PackageAddScenes(builder, scenes):
    builder.PrependUOffsetTRelativeSlot(9, flatbuffers.number_types.UOffsetTFlags.py_type(scenes), 0)

def AddScenes(builder, scenes):
    PackageAddScenes(builder, scenes)

def PackageStartScenesVector(builder, numElems):
    return builder.StartVector(4, numElems, 4)

def StartScenesVector(builder, numElems: int) -> int:
    return PackageStartScenesVector(builder, numElems)

def PackageEnd(builder):
    return builder.EndObject()

def End(builder):
    return PackageEnd(builder)
