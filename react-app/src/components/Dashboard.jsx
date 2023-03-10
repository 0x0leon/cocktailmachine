import React, { Component, useEffect } from 'react'
import { Alert, Button, Card, CardGroup, Col, Container, Row, Stack } from 'react-bootstrap'
import { io } from "socket.io-client";


export default class Dashboard extends Component {


    constructor() {
        super()

        this.state = {
            coms: [],
            clicks: 0,
            bottleData: [],
            motorData: []
        }
    }

    componentDidMount() {
        /*

        Fetched Daten aus dem socketio um zu prüfen, ob die Motoren noch laufen


        io.on('data', function (data) {
            this.setState(prev => ({ coms: prev.coms.push(data) }))
        })
        */
        console.log("mounted")
    }

    componentDidUpdate() {
        console.log(this.state.bottleData)
    }


    async sendParam(param) {

        this.setState(prev => ({ clicks: prev.clicks + 1 }))


        fetch('http://127.0.0.1:3000/machine/dashboard', {
            method: "POST",
            headers: {
                'Content-type': 'application/json'
            },
            body: JSON.stringify({ mode: param })
        })
            .then((response) => response.json())
            .then((result) => {
                console.log(result)
            })
    }

    data = [
        { motor: 1, status: 1 },
        { motor: 2, status: 1 },
        { motor: 3, status: 1 },
        { motor: 4, status: 1 },
        { motor: 5, status: 1 }
    ];



    render() {
        return (
            <Container>
                <h1>Motorsteuerung</h1>
                <Stack className='m-5' direction="horizontal" gap={1}>
                    <Button onClick={() => this.sendParam('on')} name='motoron' data-state="on" variant='primary' size='lg'>Motor an</Button>
                    <h3>count: {this.state.clicks}</h3>
                </Stack>
                <CardGroup className='m-5'>
                    <Card>
                        <Card.Title>Motoren</Card.Title>
                        Bottlechart
                    </Card>
                    <Card>
                        <Card.Title>Flaschen</Card.Title>
                        Bottlechart
                    </Card>
                </CardGroup>

                {
                    this.state.coms.map((item) => (
                        <p>{item}</p>
                    ))
                }
            </Container>
        )
    }
}
