import React, { Component } from 'react'
import { Navbar, Container, Nav } from 'react-bootstrap'
import { Link } from 'react-router-dom'

export default class NavigationBar extends Component {
    render() {
        return (
            <Navbar bg="info" variant="light">
                <Container>
                    <Navbar.Brand href="/">Cocktailmaster</Navbar.Brand>
                    <Nav className="me-auto">
                    <Link className='nav-link' to={'/'}>Home</Link>
                    <Link className='nav-link' to={'/dashboard'}>Dashboard</Link>
                    <Link className='nav-link' to={'/cocktails'}>Cocktails</Link>
                    </Nav>
                </Container>
            </Navbar>
        )
    }
}
