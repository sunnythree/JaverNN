#ifndef __JAVERNN_SOFTMAX_H__
#define __JAVERNN_SOFTMAX_H__

#include "javernn/op.h"

namespace javernn{
    class Softmax :public Op{
    public:
        Softmax(std::string name, uint32_t batch_size, uint32_t in_dim);
        ~Softmax();
        void Setup();
        void ForwardCpu(); 
        void BackwardCpu();
        void UpdateWeightsCpu(Optimizer &opt);

#ifdef GPU
        void ForwardGpu(); 
        void BackwardGpu();
        void UpdateWeightsGpu(Optimizer &opt);
#endif
    private:
        uint32_t batch_size_;
        uint32_t in_dim_;
        uint32_t temperature_;
    };
}
#endif