import React, { Component } from 'react'
import { Navbar, Container, Nav } from 'react-bootstrap'
import { Link } from 'react-router-dom'

export default class NavigationBar extends Component {
    render() {
        return (
            <Navbar bg="danger" variant="light">
                <Container>
                    <Navbar.Brand href="/">TEST</Navbar.Brand>
                    <Nav className="me-auto">
                    <Link className='nav-link' to={'/'}>Home</Link>
                    <Link className='nav-link' to={'/dashboard'}>Dashboard</Link>
                    <Link className='nav-link' to={'/cocktails'}>xxxxxxxxx</Link>
                    </Nav>
                </Container>
            </Navbar>
        )
    }
}
