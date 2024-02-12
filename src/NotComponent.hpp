#ifndef NOTCOMPONENT_HPP_
#define NOTCOMPONENT_HPP_

#include <nts/AComponent.hpp>

namespace nts {
class NotComponent : public AComponent {
    public:
        NotComponent();
        ~NotComponent() override;
        void simulate(std::size_t tick) override;
        virtual Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
};
}

#endif // NOTCOMPONENT_HPP_