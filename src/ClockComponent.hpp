#ifndef CLOCKCOMPONENT_HPP_
#define CLOCKCOMPONENT_HPP_

#include <nts/AComponent.hpp>

namespace nts {
class ClockComponent : public AComponent {
    public:
        ClockComponent();
        ~ClockComponent() override;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

    private:
        Tristate _state;
        std::size_t _lastTick;
};

}

#endif // !CLOCKCOMPONENT_HPP_
