#include <Gate4030.hpp>

nts::Gate4030::Gate4030()
{
    _inToOut = { { 1, 3 }, { 2, 3 },
        { 5, 4 }, { 6, 4 },
        { 8, 10 }, { 9, 10 },
        { 12, 11 }, { 13, 11 } };
    _outToGate = { { 3, 0 }, { 4, 1 }, { 10, 2 }, { 11, 3 } };
    _inToGateIn = { { 1, 1 }, { 2, 2 },
        { 5, 1 }, { 6, 2 },
        { 8, 1 }, { 9, 2 },
        { 12, 1 }, { 13, 2 } };

    for (size_t i = 0; i < 4; i++) {
        xorGates.push_back(std::make_unique<XorComponent>());
    }
}

nts::Gate4030::~Gate4030()
{
}

void nts::Gate4030::simulate(std::size_t tick)
{
}

nts::Tristate nts::Gate4030::compute(std::size_t pin)
{

    if (_outToGate.find(pin) != _outToGate.end()) {
        size_t gateIndex = _outToGate[pin];
        return xorGates[gateIndex]->compute(3);
    }
    return Tristate::Undefined;
}

void nts::Gate4030::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

    if (_inToOut.find(pin) == _inToOut.end()) {
        return;
    }
    size_t gateIndex = _outToGate[_inToOut[pin]];
    size_t gateInput = _inToGateIn[pin];
    xorGates[gateIndex]->setLink(gateInput, other, otherPin);
    _links[pin] = std::make_pair(&other, otherPin);
}