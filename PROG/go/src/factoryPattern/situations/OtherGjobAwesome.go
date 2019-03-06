package situations

type OtherGjobAwesome struct {
	situation string
	text      string
}

func (oa *OtherGjobAwesome) Start() {
	oa.situation = "OtherGjobAwesome"
	oa.text = " VOLUNTEER, TPM, CREATIVITY, EDU, PILOT LICENSE ahead!!!"
}

func (oa *OtherGjobAwesome) GetAction() string {
	initialString := "Your are in " + oa.situation + " so everything is perfect!!!"
	return initialString + oa.text
}
