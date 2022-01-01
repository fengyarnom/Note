
import React from "react";
import {
  BrowserRouter,
  Routes,
  Route,
  Link
} from "react-router-dom";

import Index from "./pages/Index";
import Admin from "./pages/Admin";
import Hello from "./pages/Hello";

function App() {
  return (
    <BrowserRouter>
      <Link to='/Index'>Index</Link>
      <Link to='/Admin'>Admin</Link>
      <Link to='/Hello'>Hello</Link>
      <Routes>
        <Route path="Index" element={<Index />} />
        <Route path="Admin" element={<Admin />} />
        <Route path="Hello" element={<Hello />} />
      </Routes>
    </BrowserRouter>
    
  );
}

export default App;
