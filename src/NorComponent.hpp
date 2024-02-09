#ifndef NORCOMPONENT_HPP_
#define NORCOMPONENT_HPP_

#include <nts/AComponent.hpp>

namespace nts {
class NorComponent : public AComponent {
    public:
        NorComponent();
        ~NorComponent() override;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
};

}
#endif // !NORCOMPONENT_HPP_