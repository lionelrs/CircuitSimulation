#ifndef ANDCOMPONENT_HPP_
#define ANDCOMPONENT_HPP_

#include <nts/AComponent.hpp>

namespace nts {
class AndComponent : public AComponent {
    public:
        AndComponent();
        ~AndComponent() override;
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
};

}
#endif // !ANDCOMPONENT_HPP_