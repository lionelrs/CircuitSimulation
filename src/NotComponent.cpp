#include <NotComponent.hpp>

nts::NotComponent::NotComponent()
{
}

nts::NotComponent::~NotComponent()
{
}

void nts::NotComponent::simulate(std::size_t tick)
{
    _inToOut = { { 1, 3 }, { 2, 3 } };
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (_links.find(1) == _links.end() || pin != 2) {
        return Tristate::Undefined;
    }

    auto linkedComponent = _links[1].first;
    auto linkedPin = _links[1].second;
    Tristate state = linkedComponent->compute(linkedPin);

    if (state == Tristate::True) {
        return Tristate::False;
    } else if (state == Tristate::False) {
        return Tristate::True;
    } else {
        return Tristate::Undefined;
    }
}

void nts::NotComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _links[pin] = std::make_pair(&other, otherPin);
}