import React, { Component } from 'react'
import { Button, Col, Container, Row, Stack } from 'react-bootstrap'

export default class Dashboard extends Component {



    async sendParam(param) {

        const payload = {
            mode : param
        }
        fetch('http://127.0.0.1:3000/machine/dashboard', {
            method: "POST",
            headers: {
                'Content-type': 'application/json'
            },
            body: JSON.stringify(payload)
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
                    <Button onClick={() => this.sendParam('on')} name='motoron' data-state="on" variant='info' size='lg'>Motor an</Button>
                    <Button onClick={() => this.sendParam('off')} name='motoroff' data-state="off" variant='info' size='lg'>Motor aus</Button>
                </Stack>
            </Container>
        )
    }
}
