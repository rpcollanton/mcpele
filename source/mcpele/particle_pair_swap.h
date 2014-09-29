#ifndef _MCPELE_PARTICLE_PAIR_SWAP_H__
#define _MCPELE_PARTICLE_PAIR_SWAP_H__

#include <random>

#include "mc.h"

namespace mcpele {

class ParticlePairSwap : public TakeStep {
private:
    size_t m_seed;
    std::mt19937_64 m_generator;
    std::uniform_int_distribution<size_t> m_distribution;
    const size_t m_nr_particles;
    const size_t m_swap_every;
public:
    virtual ~ParticlePairSwap() {}
    ParticlePairSwap(const size_t, const size_t, const size_t);
    void displace(pele::Array<double>& coords, MC* mc);
    void swap_coordinates(const size_t, const size_t, pele::Array<double>&);
    size_t get_seed() const { return m_seed; }
    void set_generator_seed(const size_t inp);
};

} // namespace mcpele

#endif // #ifndef _MCPELE_PARTICLE_PAIR_SWAP_H__
