using Microsoft.AspNetCore.Mvc;
using PublicTransport.Data;
using PublicTransport.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace PublicTransport.Controllers
{
    public class TransportController : Controller
    {
        private readonly AppDbContext _db;
        public TransportController(AppDbContext db)
        {
            _db = db;
        }
        public IActionResult Index()
        {
            IEnumerable<Transport> objTrasnportsList= _db.Transports;
            return View();
        }
    }
}
