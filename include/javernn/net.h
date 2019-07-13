#ifndef __JAVERNN_NET_H__
#define __JAVERNN_NET_H__

#include "javernn/optimizer/optimizer.h"
#include "javernn/ops.h"
#include "javernn/params/net_params.h"


namespace javernn{

    class Net{
    public:
        explicit Net(NetParams &net_params);
        ~Net();
        void Construct();
        void Construct(const std::vector<Op *> &input,
                 const std::vector<Op *> &output);
        void Train();
        void Test();
        void Save();
        void Load();
    private:
        std::shared_ptr<Ops> ops_;
        uint32_t max_train_iters_;
    };
}

#endif