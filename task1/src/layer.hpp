#ifndef __LAYER_H
#define __LAYER_H

#include "balancer.hpp"

class Layer
{
public:
    Layer(const int width);
    virtual ~Layer();

    int traverse(const int input);

private:
    const int width;
    Balancer *layer;
};

Layer::Layer(const int width) :
    width(width)
{
    layer = new Balancer[width];
}

Layer::~Layer()
{
    delete[] layer;
}

int
Layer::traverse(const int input)
{
    const int toggle = layer[input].traverse();

    int hi, lo;
    if (input < width / 2) {
        lo = input;
        hi = width - input - 1;
    } else {
        lo = width - input - 1;
        hi = input;
    }

    return (toggle == 0) ? lo : hi;
}

#endif /* __LAYER_H */
