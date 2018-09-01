package main

import (
	"encoding/json"
	"fmt"
	"bytes"
	"time"
	"strconv"
	"github.com/hyperledger/fabric/core/chaincode/shim"
	"github.com/hyperledger/fabric/protos/peer"
)

type MarblesChaincode struct{

}

type marble struct{
	ObjectType string `json:"objectType"`
	Name string `json:"name"`
	Color string `json:"color"`
	Size int `json:"size"`
	Owner string `json:"owner"`
}

func (t *MarblesChaincode) Init (stub shim.ChaincodeStubInterface) peer.Response {
	return shim.Success(nil)
}

func (t *MarblesChaincode) Invoke (stub shim.ChaincodeStubInterface) peer.Response {

	fn , args := stub.GetFunctionAndParameters()

	if fn == "initMarble" {
		return t.initMarble(stub, args)
	} else if fn == "readMarble" {
		return t.readMarble(stub, args)
	} else if fn == "deleteMarble" {
		return t.deleteMarble(stub,args)
	} else if fn == "transferMarble" {
		return t.transferMarble(stub, args)
	} else if fn == "getMarblesByRange"{
		return t.getMarblesByRange(stub,args)
	} else if fn == "queryMarblesByOwner" {
		return t.queryMarblesByOwner(stub, args)
	} else if fn == "getHistoryForMarble" {
		return t.getHistoryForMarble(stub,args)
	}

	return shim.Error("没有相应的方法！")
}

func (t *MarblesChaincode) initMarble (stub shim.ChaincodeStubInterface, args [] string) peer.Response{

	marblename := args[0]

	//判断 marble 是否存在
	marbleAsBytes , err := stub.GetState(marblename)

	if err != nil {
		return shim.Error(err.Error())
	}

	if marbleAsBytes != nil {
		return shim.Error("marble 已经存在！")
	}

	color := args[1]

	size, err := strconv.Atoi(args[2])

	if err != nil {
		return shim.Error("size 必须传数字字符串")
	}

	owner := args[3]
	objectType := "marble"
	marble := &marble{objectType,marblename,color,size,owner}
	
	marbleJsonAsBytes, err := json.Marshal(marble)

	err = stub.PutState(marblename,marbleJsonAsBytes)

	if err != nil {
		return shim.Error(err.Error())
	}

	return shim.Success(nil)
}

func (t *MarblesChaincode) readMarble(stub shim.ChaincodeStubInterface, args [] string) peer.Response{

	marblename := args[0]

	marbleAsBytes , err := stub.GetState(marblename)

	if err != nil {
		return shim.Error(err.Error())
	} else if  marbleAsBytes == nil {
		return shim.Error("marble 信息不存在！")
	}

	return shim.Success(marbleAsBytes)
}

func (t *MarblesChaincode) deleteMarble(stub shim.ChaincodeStubInterface, args []string) peer.Response{

	//判断marble 是否存在

	marblename := args[0]

	marbleAsBytes , err := stub.GetState(marblename)

	if err != nil {
		return shim.Error(err.Error())
	}

	if marbleAsBytes != nil {
		// 删除 marble
		err = stub.DelState(marblename)

		if err != nil {
			return shim.Error(err.Error())
		}
	}

	return shim.Success(nil)
}

func (t *MarblesChaincode) transferMarble (stub shim.ChaincodeStubInterface, args []string) peer.Response{

	marblename := args[0]
	newOwner := args[1]

	//判断marble 是否存在

	marbleAsBytes , err := stub.GetState(marblename)

	if err != nil {
		return shim.Error(err.Error())
	} else if marbleAsBytes == nil {
		return shim.Error("marble 不存在！")
	} 

	marbleInfo := marble{}
	err = json.Unmarshal(marbleAsBytes,&marbleInfo)

	if err != nil {
		return shim.Error(err.Error())
	}

	marbleInfo.Owner = newOwner

	marbleJsonAsBytes, err := json.Marshal(marbleInfo)
	if err != nil {
		return shim.Error(err.Error())
	}

	err = stub.PutState(marblename, marbleJsonAsBytes)

	if err != nil {
		return shim.Error(err.Error())
	}

	return shim.Success(nil)
}

func(t *MarblesChaincode) getMarblesByRange( stub shim.ChaincodeStubInterface, args []string) peer.Response{

	startKey := args[0]
	endKey := args[1]

	resultIterator, err := stub.GetStateByRange(startKey,endKey)

	if err != nil {
		return shim.Error(err.Error())
	}
	defer resultIterator.Close()

	var buffer bytes.Buffer
	buffer.WriteString("[")

	isWrite := false
	for resultIterator.HasNext() {
		queryResponse, err := resultIterator.Next()

		if err != nil {
			return shim.Error(err.Error())
		}

		if isWrite == true {
			buffer.WriteString(",")
		}

		buffer.WriteString("{ \"key\": ")
		buffer.WriteString(queryResponse.Key)

		buffer.WriteString(",\"record\":")
		buffer.WriteString(string(queryResponse.Value))
		buffer.WriteString("}")
		isWrite = true
	}

	buffer.WriteString("]")

	return shim.Success(buffer.Bytes())
}

func (t * MarblesChaincode) queryMarblesByOwner (stub shim.ChaincodeStubInterface, args [] string) peer.Response {

	owner := args[0]
	queryStr := fmt.Sprintf("{\"selector\":{\"owner\":\"%s\"}}",owner)

	resultIterator, err := stub.GetQueryResult(queryStr)
	if err != nil {
		return shim.Error(err.Error())
	}

	defer resultIterator.Close()

	var buffer bytes.Buffer
	buffer.WriteString("[")

	isWrite := false 

	for resultIterator.HasNext() {
		queryResponse , err := resultIterator.Next()
		if err != nil {
			return shim.Error(err.Error())
		}

		if isWrite == true {
			buffer.WriteString(",")
		}

		buffer.WriteString("{\"key\":")
		buffer.WriteString(queryResponse.Key)
		buffer.WriteString(",\"record\": ")
		buffer.WriteString(string(queryResponse.Value))
		buffer.WriteString("}")
		isWrite = true
	}
	buffer.WriteString("]")

	return shim.Success(buffer.Bytes())
}

func (t *MarblesChaincode) getHistoryForMarble (stub shim.ChaincodeStubInterface, args [] string) peer.Response{

	marblename := args[0]

	resultIterator, err := stub.GetHistoryForKey(marblename)

	if err != nil {
		return shim.Error(err.Error())
	}

	defer resultIterator.Close()

	var buffer bytes.Buffer

	buffer.WriteString("[")

	isWrite := false
	for resultIterator.HasNext() {
		queryResponse , err := resultIterator.Next()

		if err != nil {
			return shim.Error(err.Error())
		}

		if isWrite == true {
			buffer.WriteString(",")
		}

		buffer.WriteString("{ \"TxId\":")
		buffer.WriteString(queryResponse.TxId)

		buffer.WriteString(",\"Timestamp\": ")
		buffer.WriteString(time.Unix(queryResponse.Timestamp.Seconds , int64(queryResponse.Timestamp.Nanos)).String())

		buffer.WriteString(",\"Value\": ")
		buffer.WriteString(string(queryResponse.Value))

		buffer.WriteString(",\"IsDelete\": ")
		buffer.WriteString(strconv.FormatBool(queryResponse.IsDelete))
		buffer.WriteString("}")

		isWrite = true
	}

	buffer.WriteString("]")

	return shim.Success(buffer.Bytes())
}

func main() {

	err := shim.Start(new(MarblesChaincode))
	if err != nil {
		fmt.Println("chaincode start error!")
	}
}