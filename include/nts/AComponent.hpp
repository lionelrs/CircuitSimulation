#pragma once

#include <nts/IComponent.hpp>
#include <unordered_map>
#include <vector>

namespace nts {
class AComponent : public IComponent {
    public:
        AComponent() = default;
        virtual ~AComponent() override = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts ::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;

    protected:
        std::unordered_map<std::size_t, std::pair<IComponent *, std::size_t>> _links;
        std::unordered_map<std::size_t, std::size_t> _inToOut;
};

}
