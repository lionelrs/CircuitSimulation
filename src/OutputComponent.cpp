#include <OutputComponent.hpp>

nts::OutputComponent::OutputComponent()
{
}

nts::OutputComponent::~OutputComponent()
{
}

void nts::OutputComponent::simulate(std::size_t tick)
{
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (_links.find(1) == _links.end() || pin != 1) {
        return Tristate::Undefined;
    }

    auto linkedComponent = _links[1].first;
    auto linkedPin = _links[1].second;
    return linkedComponent->compute(linkedPin);
}

void nts::OutputComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _links[pin] = std::make_pair(&other, otherPin);
}
