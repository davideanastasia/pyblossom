#include <cstdint>
#include <memory>

class BloomFilter
{
private:
    uint16_t numHashes_;
    uint16_t numBuckets_;
    uint8_t *buckets_;

public:
    BloomFilter(uint16_t numHashes, uint16_t numBuckets);

    ~BloomFilter();

    void add(const char *elem);

    bool mightContain(const char *elem);

    BloomFilter merge(const BloomFilter &other) const;
};