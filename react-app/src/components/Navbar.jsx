import React, { Component } from "react";
import { Navbar, Container, NavDropdown, Nav} from 'react-bootstrap'

export class NavbarMenu extends Component {

    constructor(props){
        super();
        this.state = {
            x : 1
        }
    }


    render(){
        return(
            <Navbar collapseOnSelect expand="lg" bg="dark" variant="dark">
            <Container>
                
            </Container>
          </Navbar>
        )
    }
}
