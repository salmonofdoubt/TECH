package situations

type NoSabbatical struct {
	situation string
	text      string
}

func (ns *NoSabbatical) Start() {
	ns.situation = "NoSabbatical"
	ns.text = " QUIT, THINK: OTHER JOB or SELF-EMPLOYED, EDU, PILOT LICENSE."
}

func (ns *NoSabbatical) GetAction() string {
	initialString := "Your are in " + ns.situation + " so you are screwed!!!"
	return initialString + ns.text
}
