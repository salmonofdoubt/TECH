package situations

type InTransition struct {
	situation string
	text      string
}

func (it *InTransition) Start() {
	it.situation = " InTransition "
	it.text = " HEALTH, MAC."
}

func (it *InTransition) GetAction() string {
	initialString := "Your are in" + it.situation + "and you need to CODE as much as possible!!!"
	return initialString + it.text
}
