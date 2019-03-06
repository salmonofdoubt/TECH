package appliances

import "errors"

//import errors to log errors when they occur

// Appliance is the main interface that describes appliances
type Appliance interface {
	Start()
	GetPurpose() string
}

//appliance types 0...
const (
	STOVE = iota
	FRIDGE
	MICROWAVE
)

//returns an Appliance Type, so an Interface
func CreateAppliance(myType int) (Appliance, error) {
	switch myType {
	case STOVE:
		return new(Stove), nil
	case FRIDGE:
		return new(Fridge), nil
	case MICROWAVE:
		return new(Microwave), nil

	default:
		return nil, errors.New("Unknown Appliance Type")
	}
}
