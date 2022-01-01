import React from "react";
import {BrowserRouter,Routes,Route,Link} from "react-router-dom";

import Admin from "../Admin";
export default class Hello extends React.Component{
    render(){
        return(
            <Link to='../Admin'>Admin</Link>
            
        )
    }
}