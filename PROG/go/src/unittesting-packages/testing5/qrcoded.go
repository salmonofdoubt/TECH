package main

import (
	"image"
	"image/png"
	"io"
	"log"
	"os"
	"unittesting-packages/testing5/qrcode"
)

func main() {
	log.Println("Hello QR Code")

	file, err := os.Create("qrcode.png")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	err = GenerateQRCode(file, "555-2368", qrcode.Version(1))
	if err != nil {
		log.Fatal(err)
	}
}

func GenerateQRCode(w io.Writer, code string, version qrcode.Version) error {
	size := version.PatternSize()
	img := image.NewNRGBA(image.Rect(0, 0, size, size))
	return png.Encode(w, img)
}
