import React, { Component } from 'react'
import { Button, Col, Container, Row, Stack } from 'react-bootstrap'

export default class Dashboard extends Component {

    constructor(){
        super()

        this.state = {
            clicks : 0
        }
    }


    async sendParam(param) {

        this.setState(prev => ({ clicks: prev.clicks + 1 }))

        fetch('http://127.0.0.1:3000/machine/dashboard', {
            method: "POST",
            headers: {
                'Content-type': 'application/json'
            },
            body: JSON.stringify({mode : param})
        })
        .then((response) => response.json())
        .then((result) => {
            console.log(result)
        })

    }


    render() {
        return (
            <Container>
                <h1>Motorsteuerung</h1>
                <Stack direction="horizontal" gap={1}>
                    <Button onClick={() => this.sendParam('on')} name='motoron' data-state="on" variant='danger' size='lg'>Motor an</Button>
                    <h1>count: {this.state.clicks}</h1>
                </Stack>
                
            </Container>
        )
    }
}
