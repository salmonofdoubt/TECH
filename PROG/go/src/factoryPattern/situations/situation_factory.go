package situations

import "errors"

//import errors to log errors when they occur

// Situation is the main interface that describes situations
type Situation interface {
	Start()
	GetAction() string
}

const (
	INTRANSITION = iota
	TRANSITIONDONE
	TRANSITIONFAILED
	OTHERGJOBAWESOME
	OTHERGJOBNOTGOOD
	NOSABBATICAL
	QUITPROGRAM
)

func Quit(myType int) {
	switch myType {
	case QUITPROGRAM:
		break
	}
}

//CreateSituation returns an Situation Type, so an Interface can take it
func CreateSituation(myType int) (Situation, error) {
	switch myType {
	case INTRANSITION:
		return new(InTransition), nil
	case TRANSITIONDONE:
		return new(TransitionDone), nil
	case TRANSITIONFAILED:
		return new(TransitionFailed), nil
	case OTHERGJOBAWESOME:
		return new(OtherGjobAwesome), nil
	case OTHERGJOBNOTGOOD:
		return new(OtherGjobNotGood), nil
	case NOSABBATICAL:
		return new(NoSabbatical), nil

	default:
		return nil, errors.New("Unknown Situation, change into know Situation now.")
	}
}
