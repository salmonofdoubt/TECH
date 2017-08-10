package situations

type OtherGjobNotGood struct {
	situation string
	text      string
}

func (ij *OtherGjobNotGood) Start() {
	ij.situation = "OtherGjobNotGood"
	ij.text = " Consider STRESS DISORDER, EDU, SABBATICAL."
}

func (ij *OtherGjobNotGood) GetAction() string {
	initialString := "Your are in " + ij.situation + " and you are screwed!!"
	return initialString + ij.text
}
