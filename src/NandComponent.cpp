#include <NandComponent.hpp>

nts::NandComponent::NandComponent()
{
    _inToOut = { { 1, 3 }, { 2, 3 } };
}

nts::NandComponent::~NandComponent()
{
}

void nts::NandComponent::simulate(std::size_t tick)
{
}

nts::Tristate nts::NandComponent::compute(std::size_t pin)
{
    if (_links.find(1) == _links.end() || _links.find(2) == _links.end() || pin != 3) {
        return Tristate::Undefined;
    }

    Tristate state1 = _links[1].first->compute(_links[1].second);
    Tristate state2 = _links[2].first->compute(_links[2].second);

    if (state1 == Tristate::True && state2 == Tristate::True) {
        return Tristate::False;
    } else if (state1 == Tristate::False || state2 == Tristate::False) {
        return Tristate::True;
    } else {
        return Tristate::Undefined;
    }
}

void nts::NandComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _links[pin] = std::make_pair(&other, otherPin);
}
