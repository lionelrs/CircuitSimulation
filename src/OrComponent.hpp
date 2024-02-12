#ifndef ORCOMPONENT_HPP_
#define ORCOMPONENT_HPP_

#include <nts/AComponent.hpp>

namespace nts {
class OrComponent : public AComponent {
    public:
        OrComponent();
        ~OrComponent() override;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
};

}
#endif // !ORCOMPONENT_HPP_