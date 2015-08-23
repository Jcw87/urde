#ifndef __RETRO_CGAMEALLOCATOR_HPP__
#define __RETRO_CGAMEALLOCATOR_HPP__

#include "IAllocator.hpp"

namespace Retro
{
class CCallStack;

class CGameAllocator : public IAllocator
{
public:
    struct SGameMemInfo
    {
    };
private:
    SGameMemInfo* x10_rootInfo;
    u32 xbc_fakeStaticOff = 0;
public:
    SGameMemInfo* FindFreeBlock(u32);
    SGameMemInfo* FindFreeBlockFromTopOfHeap(u32);
    u32 FixupAllocPtrs(SGameMemInfo*, u32, u32, EHint, const CCallStack&);
    void UpdateAllocDebugStats(u32, u32, u32);
    bool FreeNormalAllocation(void*);
    u32 GetFreeBinEntryForSize(u32);
    void AddFreeEntryToFreeList(SGameMemInfo*);
    void RemoveFreeEntryFromFreeList(SGameMemInfo*);
    void DumpAllocations() const;
    u32 GetLargestFreeChunk() const;
    SGameMemInfo* GetMemInfoFromBlockPtr(void* ptr)
    {return reinterpret_cast<SGameMemInfo*>(reinterpret_cast<u8*>(ptr) - 32);}

    bool Initialize(COsContext&);
    void Shutdown();
    void* Alloc(u32, EHint, EScope, EType, const CCallStack&);
    void Free(void*);
    void ReleaseAll();
    void* AllocSecondary(u32, EHint, EScope, EType, const CCallStack&);
    void FreeSecondary(void*);
    void ReleaseAllSecondary();
    void SetOutOfMemoryCallback(const TOutOfMemoryCallback, void*);
    int EnumAllocations(const TAllocationVisitCallback, void*, bool) const;
    SAllocInfo GetAllocInfo(void*) const;
    void OffsetFakeStatics(int);
    SMetrics GetMetrics() const;
};

}

#endif // __RETRO_CGAMEALLOCATOR_HPP__
