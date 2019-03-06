package situations

type TransitionDone struct {
	situation string
	text      string
}

func (td *TransitionDone) Start() {
	td.situation = " TransitionDone "
	td.text = " VOLUNTEERING, TPM, CREATIVITY, PILOT LICENSE ahead!!!"
}

func (td *TransitionDone) GetAction() string {
	return "Your are in " + td.situation + " so you are done!!!" + td.text
}
