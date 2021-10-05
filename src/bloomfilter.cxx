#include "bloomfilter.hxx"
#include "fnv1a.hxx"

#include <cstdlib>
#include <assert.h>

BloomFilter::BloomFilter(uint16_t numHashes, uint16_t numBuckets)
{
    numHashes_ = numHashes;
    numBuckets_ = numBuckets;
    buckets_ = new uint8_t[numBuckets];
}

BloomFilter::~BloomFilter()
{
    if (buckets_ != NULL)
    {
        delete[] buckets_;
    }
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

BloomFilter BloomFilter::merge(const BloomFilter &other) const
{
    assert(this->numBuckets_ == other.numBuckets_);
    assert(this->numHashes_ == other.numHashes_);

    BloomFilter obj = BloomFilter(other.numHashes_, other.numBuckets_);

    for (int i = 0; i < other.numBuckets_; i++)
    {
        obj.buckets_[i] = this->buckets_[i] | other.buckets_[i];
    }

    return obj;
}