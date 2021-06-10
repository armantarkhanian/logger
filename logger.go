// Package logger ...
package logger

import (
	"fmt"
	"log"
	"os"
	"path/filepath"
	"runtime"
	"strconv"
	"strings"
	"time"
)

var (
	logFile *os.File
)

func Init(dir string, filename string) {
	if err := os.MkdirAll(dir, 0777); err != nil {
		panic(err)
	}

	filename = filepath.Join(dir, filename)

	var err error
	logFile, err = os.OpenFile(filename, os.O_RDWR|os.O_CREATE|os.O_APPEND, 0666)
	if err != nil {
		log.Fatalln(err)
	}
}

func checkInitialized() {
	if logFile == nil {
		panic("logger: log file not initialized")
	}
}

func Info(v ...interface{}) {
	checkInitialized()
	logFile.WriteString(output("[INFO] ", fmt.Sprint(v...)))
}

func Error(v ...interface{}) {
	checkInitialized()
	logFile.WriteString(output("[ERROR]", fmt.Sprint(v...)))
}

func Warning(v ...interface{}) {
	checkInitialized()
	logFile.WriteString(output("[WARN] ", fmt.Sprint(v...)))
}

func Fatal(v ...interface{}) {
	checkInitialized()
	logFile.WriteString(output("[FATAL]", fmt.Sprint(v...)))
	os.Exit(1)
}

func Infof(format string, v ...interface{}) {
	checkInitialized()
	logFile.WriteString(output("[INFO] ", fmt.Sprintf(format, v...)))
}

func Errorf(format string, v ...interface{}) {
	checkInitialized()
	logFile.WriteString(output("[ERROR]", fmt.Sprintf(format, v...)))
}

func Warningf(format string, v ...interface{}) {
	checkInitialized()
	logFile.WriteString(output("[WARN] ", fmt.Sprintf(format, v...)))
}

func Fatalf(format string, v ...interface{}) {
	checkInitialized()
	logFile.WriteString(output("[FATAL]", fmt.Sprintf(format, v...)))
	os.Exit(1)
}

func output(prefix string, data string) string {
	var (
		file string
		line int
		ok   bool
	)
	_, file, line, ok = runtime.Caller(2)
	if !ok {
		file = "???"
		line = 0
	}
	short := file
	for i := len(file) - 1; i > 0; i-- {
		if file[i] == '/' {
			short = file[i+1:]
			break
		}
	}
	file = short

	caller := file + ":" + strconv.Itoa(line) + ":"
	value := 20 - len(caller)
	if value >= 0 {
		caller = strings.Repeat(".", value) + caller
	} else {
		value = value * (-1)
		caller = caller[value:]
	}
	t := time.Now().UTC().Format("2006/02/01 15:04:05") + " "
	return t + caller + " " + prefix + " " + data + "\n"
}
