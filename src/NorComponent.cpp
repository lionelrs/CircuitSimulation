#include <NorComponent.hpp>

nts::NorComponent::NorComponent()
{
    _inToOut = { { 1, 3 }, { 2, 3 } };
}

nts::NorComponent::~NorComponent()
{
}

void nts::NorComponent::simulate(std::size_t tick)
{
}

nts::Tristate nts::NorComponent::compute(std::size_t pin)
{
    if (_links.find(1) == _links.end() || _links.find(2) == _links.end() || pin != 3) {
        return Tristate::Undefined;
    }

    Tristate state1 = _links[1].first->compute(_links[1].second);
    Tristate state2 = _links[2].first->compute(_links[2].second);

    if (state1 == Tristate::False && state2 == Tristate::False) {
        return Tristate::True;
    } else if (state1 == Tristate::False && state2 == Tristate::Undefined) {
        return Tristate::Undefined;
    } else if (state1 == Tristate::Undefined && state2 == Tristate::False) {
        return Tristate::Undefined;
    } else {
        return Tristate::False;
    }
}

void nts::NorComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _links[pin] = std::make_pair(&other, otherPin);
}