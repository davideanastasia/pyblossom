#include "bloomfilter.hxx"
#include "fnv1a.hxx"

#include <cstdlib>

BloomFilter::BloomFilter(uint16_t numHashes, uint16_t numBuckets)
{
    numHashes_ = numHashes;
    numBuckets_ = numBuckets;
    buckets_ = new uint8_t[numBuckets];
}

BloomFilter::~BloomFilter()
{
    delete[] buckets_;
}

void BloomFilter::add(const char *elem)
{
    for (int i = 0; i < numHashes_; i++)
    {
        uint64_t currHash = fnv1a(elem, i);
        uint64_t idx = currHash % numBuckets_;
        buckets_[idx] = 1;
    }
}

bool BloomFilter::mightContain(const char *elem)
{
    for (int i = 0; i < numHashes_; i++)
    {
        uint64_t currHash = fnv1a(elem, i);
        uint64_t idx = currHash % numBuckets_;
        if (buckets_[idx] == 0)
        {
            return false;
        }
    }
    return true;
}